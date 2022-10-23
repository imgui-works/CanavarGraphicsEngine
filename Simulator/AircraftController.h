#ifndef AIRCRAFTCONTROLLER_H
#define AIRCRAFTCONTROLLER_H

#include "Aircraft.h"

#include <Model.h>

#include <PointLight.h>
#include <QKeyEvent>
#include <QObject>
#include <QSet>
#include <QTimer>

#include <imgui.h>
#include <QtImGui.h>

class AircraftController : public QObject
{
    Q_OBJECT
public:
    explicit AircraftController(Aircraft *aircraft, QObject *parent = nullptr);

    void keyPressed(QKeyEvent *);
    void keyReleased(QKeyEvent *);

    void drawGUI();
    void setJet(Canavar::Engine::Model *newJet);
    void setRootJetNode(Canavar::Engine::Node *newRootJetNode);

signals:
    void command(Aircraft::Command command, QVariant variant = QVariant());

public slots:
    bool init();
    void tick();
    void update(float ifps);

private:
    QVariant getCmd(Aircraft::Command command, QVariant value);

    void lights(bool lit);

private:
    Aircraft *mAircraft;
    QSet<Qt::Key> mPressedKeys;
    QTimer mTimer;

    float mAileron;  // [-1, 1]
    float mElevator; // [-1, 1]
    float mRudder;   // [-1, 1]
    float mThrottle; // [0, 1]

    Aircraft::PrimaryFlightData mPfd;

    Canavar::Engine::Model *mJet;
    Canavar::Engine::Node *mRootJetNode;
    Canavar::Engine::PointLight *mRedLight;
    Canavar::Engine::PointLight *mGreenLight;

    bool mAutoPilotEnabled;

    float mTimeElapsed;
};

#endif // AIRCRAFTCONTROLLER_H
