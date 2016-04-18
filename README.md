# WemosD1mini_ATS_Dashboard
Shows data from https://github.com/Funbit/ets2-telemetry-server on Wemos D1 Mini. 

Requires Wemos D1 Mini and OLED shield. Written in ~4 hours (most of it was playtesting though)

![How it looks](https://pbs.twimg.com/media/CgWyDu_WQAAxW2l.jpg)

# How to use

Install and run this: https://github.com/Funbit/ets2-telemetry-server

Install whatever php server solution you want. I prefer XAMPP.

Copy the data.php to the www or htdocs or whatever http root folder your server uses. (The ram of Wemos D1 Mini is not enough to download and parse the whole JSON.)

Install ATSDashboard.ino file to your Wemos D1 Mini (edit wifi and ip settings before that).

Enjoy your speedometer!
