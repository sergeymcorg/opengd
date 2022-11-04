#include "GameManager.h"

#if ENABLE_DISCORD == 1
#include "./Discord/cpp/discord.h"
#include "CompileLayer.h"

discord::Core* dCore{};
#endif

GameManager* GameManager::getInstance() {
    static GameManager* g_pGM = new(std::nothrow) GameManager();
    // static GameManager* g_pGM;

    // if (!g_pGM) {
    //     g_pGM = new(std::nothrow) GameManager();
    //     g_pGM->setDefaults();
    // }

    return g_pGM;
}

bool GameManager::hasVariable(string name) {
    return this->m_values.contains(name);
}

void GameManager::setDefaults() {
    json defaults = {
        {"player-cube", 1},
        {"player-main-color", 0},
        {"player-secondary-color", 3},
        {"player-username", "Player"}
    };

    for (auto& [key, value] : defaults.items()) {
        log_ << key << " : " << value << ";" << this->hasVariable(key);
        if (!this->hasVariable(key))
            this->setVariable(key, value);
    }
    this->save();
}

void GameManager::save() {
    auto path = FileUtils::getInstance()->getWritablePath() + "/GameManager.json";

    std::ofstream file(path);
    if (file.good())
        file << this->m_values.dump(4);
    else
        log_ << "Failed to save GameManager!";
    file.close();
}

void GameManager::loadFromSave() {
    auto path = FileUtils::getInstance()->getWritablePath() + "/GameManager.json";

    std::ifstream file(path);
    if (file.good())
        this->m_values = json::parse(file);
    else
        log_ << "Failed to load GameManager!";
    file.close();

    this->setDefaults();
}

bool GameManager::connectDiscord() {
	
#if ENABLE_DISCORD == 1
    if (!ENABLE_DISCORD) return false;

    // 690545589175451679
    discord::Result result = discord::Core::Create(690545589175451679, DiscordCreateFlags_NoRequireDiscord, &dCore);
    if ((int)result != EDiscordResult::DiscordResult_Ok) {
        log_ << "Failed to connect to Discord due to " << (int)result << "!";
        return false;
    }

    return true;
#else
	return false;
#endif
}
bool GameManager::changeDActivity() {
#if	ENABLE_DISCORD == 1
    if (!dCore) return false;

    Director::getInstance()->getRunningScene()->schedule([](float t) {
        GM->processDiscord(t);
    }, "discord");
    

    discord::Activity activity{};
    auto cll = CompileLayer::create();
    activity.SetState(cll->getRandom().c_str());
    activity.SetDetails("Browsing menus");
    activity.SetType(discord::ActivityType::Playing);
    activity.GetAssets().SetLargeImage("gjlogo");
    activity.GetAssets().SetLargeText("OpenGD 1.0 DEV");
    /*
    activity.GetParty().SetId("221");
    activity.GetParty().SetPrivacy(discord::ActivityPartyPrivacy::Public);
    activity.GetParty().GetSize().SetCurrentSize(1);
    activity.GetParty().GetSize().SetMaxSize(16);
    */
    activity.GetSecrets().SetJoin("1AF");
    activity.GetSecrets().SetMatch("111J");
    activity.GetSecrets().SetSpectate("21FF");
    activity.SetInstance(true);
    dCore->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
        if ((int)result != EDiscordResult::DiscordResult_Ok) {
            log_ << "Failed to change DActivity due to " << (int)result << "!";
        }
        Director::getInstance()->getRunningScene()->unschedule("discord");
    });
    this->createDiscordSession();

    dCore->ActivityManager().OnActivityJoin.Connect([](const char *secret) {
        log_ << "Someone joined!!!";
        dCore->LobbyManager().ConnectLobbyWithActivitySecret(secret, [](discord::Result, discord::Lobby lobby) {
            GM->createMultiplayerSession(lobby.GetId());
            /*
            for (int i = 0; i < (int)dCore->LobbyManager().MemberCount(); i++) {
                discord::UserId* uid = (discord::UserId*)malloc(sizeof(discord::UserId));
                discord::Result res = dCore->LobbyManager().GetMemberUserId(lobby.GetId(), i, uid);
                if ((int)res == DiscordResult_Ok) {
                    dCore->LobbyManager().SendNetworkMessage(lobby.GetId(), uid[0], 0, (uint8_t*)"Hello!", 7);
                }
            }
            */
        });
    });

    return true;
#else
    return false;
#endif
}
void GameManager::processDiscord(float t) {
#if ENABLE_DISCORD == 1
    dCore->RunCallbacks();
#endif
    return;
}

bool GameManager::createMultiplayerSession(uint64_t lid) {
#if ENABLE_DISCORD == 1

    dCore->LobbyManager().ConnectNetwork(lid);
    
    dCore->LobbyManager().OpenNetworkChannel(lid, 0, false);

    return true;
#else
    return false;
#endif
}

uint64_t GameManager::createDiscordSession() {
#if ENABLE_DISCORD == 1
    discord::LobbyTransaction txn;
    dCore->LobbyManager().GetLobbyCreateTransaction(&txn);
    txn.SetCapacity(16);
    txn.SetType(discord::LobbyType::Public);
    txn.SetLocked(false);
    dCore->LobbyManager().CreateLobby(txn, [](discord::Result res, discord::Lobby lobby) {
        if ((int)res == (int)discord::Result::Ok) {
            log_ << "Made DLobby " << (uint64_t)lobby.GetId();
        }
        else {
            log_ << "Failed to create DLobby due to " << (int)res << "!";
        }
    });
    return UINT64_MAX;
#else
    return UINT64_MAX;
#endif;
}