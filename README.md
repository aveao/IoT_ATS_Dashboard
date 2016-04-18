# American Truck Simulator / Euro Truck Simulator 2 Dashboard for Wemos D1 Mini

Shows data from https://github.com/Funbit/ets2-telemetry-server on Wemos D1 Mini. Should work with other ESP8266 models too, or even other Arduinos.

Requires Wemos D1 Mini and OLED shield. Written in ~4 hours (most of it was playtesting though)


![How it looks 2](http://i.imgur.com/nog3AaS.jpg)

# How to use

Install and run this: https://github.com/Funbit/ets2-telemetry-server

Install whatever php server solution you want. I prefer XAMPP.

Copy the data.php to the www or htdocs or whatever http root folder your server uses. (The ram of Wemos D1 Mini is not enough to download and parse the whole JSON.) If you didn't already, start your php server (Start button next to Apache on XAMPP).

Install ATSDashboard.ino file to your Wemos D1 Mini (edit wifi and ip settings before that) using Arduino IDE, you'll need to download some libraries and the device profile.

Enjoy your speedometer!
