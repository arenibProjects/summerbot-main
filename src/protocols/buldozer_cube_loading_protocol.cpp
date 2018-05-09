#include "buldozer_cube_loading_protocol.hpp"
#include "../../robot.h"
#include "../../ia.hpp"
#include "../../nodes.hpp"
#include <Arduino.h>

void BuldozerCubeLoadingProtocol::update(IA *ia){ //execute the next action of this protocol
  switch(state){
    case 0:
    ia->mb->moveTo(RoadBuldozerCubeLoadingZone[loadingZone].getX(),
              RoadBuldozerCubeLoadingZone[loadingZone].getY(ia->getFlag("side")),
              RoadBuldozerCubeLoadingZone[loadingZone].getA(ia->getFlag("side"));
    Serial.println("LOG Starting_BuldozerCubeLoadingProtocol_#"+String(loadingZone));
    break;
    case 1:
    ia->mb->moveTo(RealBuldozerCubeLoadingZone[loadingZone].getX(),
              RealBuldozerCubeLoadingZone[loadingZone].getY(ia->getFlag("side")),
              RealBuldozerCubeLoadingZone[loadingZone].getA(ia->getFlag("side"));
    Serial.println("LOG Moving_Toward_LoadingZone_#"+String(loadingZone));
    break;
    case 2:
    short unloadingZone=0;
    for(;ia->getFlag("cross"+(String)unloadingZone+"SuccessfullyCleared");unloadingZone++);
    ia->mb->moveTo(unloadingZones[unloadingZone].getX(),
              unloadingZones[unloadingZone].getY(ia->getFlag("side")),
              PI);

    ia->setFlag("cross"+(String)unloadingZone+"SuccessfullyCleared", 1);
    Serial.println("LOG PushingCubesViolently.lol._Direction_UnloadingZone_#"+(String)unloadingZone);
    break;
    default:
    // Anomality
    break;
  }
  state++;
}

boolean BuldozerCubeLoadingProtocol::isCompleted(){ //wether the last action of this protocol have already been executed or not
  return state>2;
}

unsigned short int BuldozerCubeLoadingProtocol::getPriority(IA *ia){
  return priority;
}
