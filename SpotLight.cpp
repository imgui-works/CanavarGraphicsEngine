#include "SpotLight.h"

SpotLight::SpotLight(QObject *parent)
    : PointLight(parent)
    , mDirection(0, -1, 0)
    , mCutOffAngle(1.04f)
    , mOuterCutOffAngle(2.1f)
{}

const QVector3D &SpotLight::direction() const
{
    return mDirection;
}

void SpotLight::setDirection(const QVector3D &newDirection)
{
    mDirection = newDirection;
}

float SpotLight::cutOffAngle() const
{
    return mCutOffAngle;
}

void SpotLight::setCutOffAngle(float newCutOffAngle)
{
    mCutOffAngle = newCutOffAngle;
}

float SpotLight::outerCutOffAngle() const
{
    return mOuterCutOffAngle;
}

void SpotLight::setOuterCutOffAngle(float newOuterCutOffAngle)
{
    mOuterCutOffAngle = newOuterCutOffAngle;
}
