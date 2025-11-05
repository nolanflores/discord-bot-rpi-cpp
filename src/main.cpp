#include <iostream>
#include <dpp/dpp.h>

#include "discord_token.hpp"

int main() {
    dpp::cluster bot(DISCORD_TOKEN, dpp::i_default_intents | dpp::i_message_content);

    //bot.on_log(dpp::utility::cout_logger());

    bot.on_message_create([&bot](const dpp::message_create_t& event){
        //bot.log(dpp::loglevel::ll_info, "Message received: " + event.msg.content);

        if (event.msg.author.is_bot())
            return;

        const std::string& raw = event.msg.content;
        if (raw.empty() || raw.front() != '!')
            return;

        size_t index = raw.find(' ');
        std::string cmd = (index == std::string::npos) ? raw : raw.substr(0, index);
        std::string content = (index == std::string::npos) ? std::string() : raw.substr(index + 1);

        if (cmd == "!say")
            bot.message_create(dpp::message(event.msg.channel_id, content));
        else if(cmd == "!buddy")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/hey-buddy-you-have-to-be-quiet-people-don%27t-like-you-hey-buddy-you-have-to-be-quiet-because-hey-buddy-you-have-to-be-quiet-because-people-don%27t-like-you-gif-3338348331317023398"));
        else if(cmd == "!bust")
            bot.message_create(dpp::message(event.msg.channel_id, "https://media.discordapp.net/attachments/945070791949709362/1146307918447255552/bust.gif"));
        else if(cmd == "!notice")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/brendan-frasier-oscars-meme-glasses-gif-17794317351170463418"));
        else if(cmd == "!nuke")
            bot.message_create(dpp::message(event.msg.channel_id, "https://cdn.discordapp.com/attachments/945070791949709362/1389203749565890600/Yapyap.gif"));
        else if(cmd == "!pray")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/collusion-trump-jabba-the-hut-gif-13001238"));
        else if(cmd == "!react")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/soldier-soldier-tf2-tf2-soldier-gaming-gif-5369387296864231941"));
        else if(cmd == "!sell")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/say-what-gif-7766983"));
        else if(cmd == "!sold")
            bot.message_create(dpp::message(event.msg.channel_id, "https://cdn.discordapp.com/attachments/945070791949709362/1406421859397795840/IMG_4698.gif"));
        else if(cmd == "!slap")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/nic-cage-nicolas-cage-slap-mom-and-dad-inhale-gif-22714577"));
        else if(cmd == "!tap")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/nemo-tap-glass-hello-gif-15153530"));
        else if(cmd == "!whip")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/whipping-johnny-rico-gif-19817777"));
        else if(cmd == "!winner")
            bot.message_create(dpp::message(event.msg.channel_id, "https://tenor.com/view/epic-win-gif-18390652"));
    });

    bot.start(dpp::st_wait);

    return 0;
}