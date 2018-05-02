#include "nodes.hpp"
Node g_roadMain =Node(350,610);
Node g_start=Node(180,200);
Node g_cross1=Node(550,650);
Node g_cross2=Node(990,300);
Node g_cross3=Node(1500,900);

Node unloadingZones[]={
  Node(180+60,500),
  Node(180+60,720),
  Node(180+60,830)};
Node RoadCubeLoadingZone[]={
  Node(540,610),
  Node(1190,610),
  Node(1500,610)};
Node RealCubeLoadingZone[]={
  Node(540,850-ROBOT_1_W_DEPLOYED),
  Node(1190,280+44+ROBOT_1_W_DEPLOYED),
  Node(1500,1100-ROBOT_1_W_DEPLOYED)
};