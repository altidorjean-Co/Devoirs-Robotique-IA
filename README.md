# Devoir N°6 : Robot à décision intelligente (ESP32)

## 🎯 Objectif du projet
L'objectif de ce projet est de concevoir un système embarqué autonome capable de prendre une décision intelligente en temps réel. Le système surveille une distance de sécurité à l'aide d'un capteur à ultrasons et déclenche automatiquement une alerte visuelle et sonore si un obstacle franchit le seuil critique défini.

## 🛠️ Composants et outils utilisés
* Plateforme de simulation : Wokwi
* Microcontrôleur : ESP32
* Capteur de distance : HC-SR04 (Ultrasons)
* Alerte Visuelle : 1 Diode Électroluminescente (LED rouge)
* Alerte Sonore : 1 Buzzer Piézoélectrique

## ⚙️ Fonctionnement du projet
1. L'ESP32 pilote le capteur HC-SR04 pour envoyer des ondes ultrasoniques et calculer la distance de l'obstacle le plus proche en centimètres.
2. Le programme applique une règle de décision logique stricte basée sur un seuil logiciel de 50 cm.
3. Logique de décision :
   * Si l'obstacle est situé à moins de 50 cm, le robot prend la décision d'activer l'alarme : la LED rouge s'allume instantanément et le buzzer émet une tonalité continue de 1 kHz. Une notification d'alerte est également poussée sur le Moniteur Série.
   * Si l'obstacle est à plus de 50 cm, l'alarme se coupe et le système reste en veille active.

## 📊 Résultats obtenus
La simulation sur Wokwi valide parfaitement le comportement algorithmique. Lorsque l'utilisateur manipule le curseur du capteur HC-SR04 sous la barre des 50 cm, la LED rouge s'illumine et le signal sonore s'active sans aucune latence. Le Moniteur Série affiche correctement le log des mesures et les changements d'état du robot.# Devoirs-Robotique-IA