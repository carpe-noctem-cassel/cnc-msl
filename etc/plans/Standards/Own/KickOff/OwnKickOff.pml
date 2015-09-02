<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1438785376159" name="OwnKickOff" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Standards/Own/KickOff" priority="0.0" minCardinality="1" maxCardinality="2147483647">
  <states id="1438785376160" name="PosExec" comment="" entryPoint="1438785376161">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/PositionExecutor.beh#1438790487994</plans>
    <outTransitions>#1440675383814</outTransitions>
  </states>
  <states id="1438785501838" name="PosRecv" comment="" entryPoint="1438785392109">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/PositionReceiver.beh#1439379352605</plans>
    <outTransitions>#1440772549851</outTransitions>
  </states>
  <states id="1440675376134" name="GrabBall" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../../../GenericStandards/StandardActuate.beh#1435766278023</plans>
    <inTransitions>#1440675383814</inTransitions>
    <inTransitions>#1440772442289</inTransitions>
    <outTransitions>#1440772545631</outTransitions>
  </states>
  <states id="1440772305591" name="Pass" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/ShovelSelect.beh#1435156714286</plans>
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/KickOffPassDefault.beh#1438778223495</plans>
    <inTransitions>#1440772545631</inTransitions>
    <outTransitions>#1440772442289</outTransitions>
  </states>
  <states id="1440772454611" name="Receive" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/AttackOpp.beh#1430324680117</plans>
    <inTransitions>#1440772549851</inTransitions>
    <outTransitions>#1440772873418</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1440772500050" name="Success" comment="">
    <inTransitions>#1440772873418</inTransitions>
  </states>
  <transitions id="1440675383814" name="PosExec2GrabBall" comment="From PosExec 2 GrabBall State: If we reached the executor position." msg="">
    <preCondition id="1440675385644" name="PosExec2GrabBall" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1438785376160</inState>
    <outState>#1440675376134</outState>
  </transitions>
  <transitions id="1440772442289" name="MISSING_NAME" comment="lost ball" msg="">
    <preCondition id="1440772443709" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1440772305591</inState>
    <outState>#1440675376134</outState>
  </transitions>
  <transitions id="1440772545631" name="MISSING_NAME" comment="grabbed ball" msg="">
    <preCondition id="1440772549250" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1440675376134</inState>
    <outState>#1440772305591</outState>
  </transitions>
  <transitions id="1440772549851" name="MISSING_NAME" comment="receiver aligned" msg="">
    <preCondition id="1440772553737" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1438785501838</inState>
    <outState>#1440772454611</outState>
  </transitions>
  <transitions id="1440772873418" name="MISSING_NAME" comment="any child success" msg="">
    <preCondition id="1440772876913" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1440772454611</inState>
    <outState>#1440772500050</outState>
  </transitions>
  <entryPoints id="1438785376161" name="MISSING_NAME" comment="" successRequired="false" minCardinality="1" maxCardinality="1">
    <task>../../../../Misc/taskrepository.tsk#1439997010902</task>
    <state>#1438785376160</state>
  </entryPoints>
  <entryPoints id="1438785392109" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../../Misc/taskrepository.tsk#1439997023446</task>
    <state>#1438785501838</state>
  </entryPoints>
</alica:Plan>