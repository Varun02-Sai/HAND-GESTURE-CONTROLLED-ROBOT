# 🤖 Hand Gesture-Controlled Robot

This project demonstrates a **gesture-controlled robotic system** developed using Arduino and various sensors. It is primarily aimed at helping individuals with limited mobility by enabling them to control a robot with simple hand movements.

## 📹 Prototype Demo

Watch the video demo of our working prototype here:  
🎥 [Prototype Video](https://drive.google.com/file/d/1dQSv3X5BS09ebSSsMRasrg3LY33LWesT/view?usp=drive_link)

---

## 👥 Team Members
- Sai Varun J [102301014]
- Fazil Metharsha Y [122301011]
- Akhil Ganesh K [132301004]
- Venkatesh M [132301020]
- Garide Avinash [122301012]
- Rahul G [102301011]
- Shashank N [102301023]


---

## 🔧 Problem Statement

Many physically challenged individuals struggle to operate traditional controls (e.g., remotes, buttons). Our goal is to provide an accessible, intuitive, and affordable solution using hand gestures to control a robot.

---

## 💡 Why This Project?

- Offers **ease of use** through natural hand movements.
- Enables **independent control** for people with disabilities.
- Can be extended to **educational toys**, **surveillance bots**, or **assistive devices**.
- Encourages **technology interaction** in a fun and meaningful way.

---

## 🧠 How It Works

### Transmitter Section
- **MPU6050** detects hand tilt on the x and y axes.
- Data is processed by **Arduino Uno** and transmitted via **NRF24L01**.

### Receiver Section
- Data is received by another **Arduino Uno** with **NRF24L01**.
- Tilt values are mapped to motor speeds using **L298N Motor Driver**.
- The robot moves according to hand gestures.

---

## 🔩 Components & Cost

| Component                  | Quantity | Cost    |
|---------------------------|----------|---------|
| Arduino Uno (with cable)  | 2        | ₹1400   |
| Robot Chassis             | 1        | ₹464    |
| L298N Motor Driver        | 1        | ₹200    |
| MPU6050 Sensor            | 1        | ₹200    |
| NRF24L01 Module           | 2        | ₹512.68 |
| Batteries & Adapter       | -        | ₹360    |
| Wires                     | -        | ₹190    |
| **Total**                 | -        | ₹4500   |

🧾 [Detailed Bill of Materials](https://drive.google.com/file/d/1dGZcJr-NjmaXm2fBtatV15cJgQQkItdo/view?usp=sharing)

---

## 🧪 Testing Process

- ✅ Component Testing
- ⚙️ Sensor Calibration
- 🧠 Software Functionality
- 📡 Range Testing
- 👤 User Testing

### Test Resources:
- [NRF24L01 Transmitter & Receiver Code](https://docs.google.com/document/d/1O5McDCFdfSNab9XLwfOIB6oDawQFpUvKop8stB0VUw8/edit?usp=sharing)
- [MPU6050 Calibration & Mapping](https://docs.google.com/document/d/1ootsM-d2ORGAdNNm5hqWnhysLHTWfzq5DseaBZAJxpk/edit?usp=sharing)

---

## 🖥️ Source Code

- [Transmitter Code](https://docs.google.com/document/d/1AzDwZbYWgyro49UXOQgKNTjERuBc-Xn7o4f8sPo6m4o/edit?usp=sharing)
- [Receiver Code](https://docs.google.com/document/d/1WstnyehJvcpaI5UhzD58sD9BOSOZxhrXsFKkeUDsES4/edit?usp=drive_link)

---

## ✅ Pros

- Natural and intuitive interface.
- Promotes accessibility.
- Suitable for various age groups.
- Educational and assistive potential.

## ❌ Cons

- Limited gesture range due to budget constraints.
- Battery-powered communication can reduce reliability.

---

## 🚀 Future Scope

- Integration with **brain-computer interfaces**.
- Application in **wheelchairs**, **drones**, and **smart homes**.
- Improved power management for better wireless communication.

---

## 📬 Contact

If you’d like to contribute or have suggestions, feel free to open an issue or contact any of the team members.

