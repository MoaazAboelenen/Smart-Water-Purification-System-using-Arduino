# Smart-Water-Purification-System-using-Arduino
💧 Smart Water Purification System using Arduino
This project is a smart, automated water purification system built using Arduino. It integrates multiple sensors and actuators to monitor and manage the purification process through a timed cycle. The system measures pH, turbidity, and TDS to ensure water quality and controls pumps, fans, and valves to carry out each purification stage.

🚀 Features
Fully automated purification cycle with timed operations

Monitors key water quality parameters:

pH level

Turbidity

TDS (Total Dissolved Solids)

Controls multiple components:

Fans for aeration or drying

Valves for flow control

12V and 5V pumps for water movement

Customizable 50-minute repeating cycle with precise control logic

Arduino-based for affordability and simplicity

🧰 Components Used
Arduino Uno

pH Sensor Module

Turbidity Sensor

TDS Sensor

12V Water Pump

5V Water Pump

Solenoid Valve (controlled via digital pin)

2x Fans (connected to digital pins)

Relay modules or transistor drivers for controlling pumps/fans

Jumper wires, breadboard, tubing

Power supply (12V + 5V or regulated)

⚙️ System Workflow
The system runs in repeating 50-minute cycles, performing the following steps:

Initial Fan & Pump Activation:

FAN1 and FAN2 run for 1 minute

Then FAN1 runs for 20s ON / 10s OFF cycles continuously

Water Circulation Phase:

PUMP12V and VALVE activate for 15 minutes

PUMP5V activates for 15 seconds every 1 minute

Quality Monitoring:

Water quality is monitored using pH, turbidity, and TDS sensors at intervals

Loop Repeat:

After 50 minutes, the cycle restarts automatically

You can customize timing and control logic easily in code.
🤝 Teamwork
This project was built through strong teamwork and collaboration. Each team member contributed to specific aspects, from hardware setup and AI training to wearable design and testing.

Team Members:
[Abdelrahman Waleed] –



