# American Truck Simulator / Euro Truck Simulator 2 Dashboard for IoT devices

Shows data from https://github.com/Funbit/ets2-telemetry-server on IoT devices. 

Wemos code is Written in ~4 hours (most of it was playtesting though)

# Supported Platforms

Wemos D1 Mini (Might work with other esp8266 or Arduino boards)

![How it looks 2](http://i.imgur.com/nog3AaS.jpg)

Coming soon: Pebble

# How to use (Wemos D1 Mini)

Install and run this: https://github.com/Funbit/ets2-telemetry-server

Install whatever php server solution you want. I prefer XAMPP.

Copy the data.php to the www or htdocs or whatever http root folder your server uses. (The ram of Wemos D1 Mini is not enough to download and parse the whole JSON.) If you didn't already, start your php server (Start button next to Apache on XAMPP).

Install ATSDashboard.ino file to your Wemos D1 Mini (edit wifi and ip settings before that) using Arduino IDE, you'll need to download some libraries and the device profile.

Enjoy your speedometer!
