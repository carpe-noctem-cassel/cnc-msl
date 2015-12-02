<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1431522123418" name="GenericExecute" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/GenericStandards" priority="0.0" minCardinality="2" maxCardinality="2147483647">
  <states id="1431522155979" name="GrabBall" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../GenericBehaviours/InterceptCarefully.beh#1427703234654</plans>
    <plans xsi:type="alica:BehaviourConfiguration">StandardActuate.beh#1435766278023</plans>
    <inTransitions>#1433949706015</inTransitions>
    <inTransitions>#1435761866545</inTransitions>
    <outTransitions>#1431522782044</outTransitions>
  </states>
  <states id="1431522297705" name="Align" comment="" entryPoint="1431522269326">
    <plans xsi:type="alica:BehaviourConfiguration">StandardAlignToPoint.beh#1433950043262</plans>
    <plans xsi:type="alica:BehaviourConfiguration">StandardActuate.beh#1435766278023</plans>
    <outTransitions>#1431522920716</outTransitions>
  </states>
  <states id="1431522763494" name="Pass" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/ShovelSelect.beh#1435156714286</plans>
    <plans xsi:type="alica:BehaviourConfiguration">StandardPass.beh#1435760175843</plans>
    <plans xsi:type="alica:BehaviourConfiguration">StandardActuate.beh#1435766278023</plans>
    <inTransitions>#1431522782044</inTransitions>
    <outTransitions>#1431524869870</outTransitions>
    <outTransitions>#1435761866545</outTransitions>
  </states>
  <states id="1431522912251" name="Receive" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/ShovelSelect.beh#1435156811453</plans>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/AttackOpp.beh#1430324680117</plans>
    <inTransitions>#1431522920716</inTransitions>
    <outTransitions>#1431523011459</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1431522995646" name="Success" comment="">
    <inTransitions>#1431523011459</inTransitions>
  </states>
  <states id="1431523482646" name="Block" comment="" entryPoint="1431523395534"/>
  <states id="1431524014799" name="Defend" comment="" entryPoint="1431523422152"/>
  <states id="1431524769489" name="SpatialDefend" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../GenericBehaviours/Stop.beh#1413992626194</plans>
    <inTransitions>#1431524869870</inTransitions>
  </states>
  <states id="1433949667740" name="Align" comment="" entryPoint="1431522155980">
    <plans xsi:type="alica:BehaviourConfiguration">StandardAlignToPoint.beh#1435155363994</plans>
    <outTransitions>#1433949706015</outTransitions>
  </states>
  <transitions id="1431522782044" name="MISSING_NAME" comment="grab ball success" msg="">
    <preCondition id="1431522783626" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1431522155979</inState>
    <outState>#1431522763494</outState>
  </transitions>
  <transitions id="1431522920716" name="MISSING_NAME" comment="aligned &amp;&amp; robot in SpatialDefend" msg="">
    <preCondition id="1431522922124" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1431522297705</inState>
    <outState>#1431522912251</outState>
  </transitions>
  <transitions id="1431523011459" name="MISSING_NAME" comment="success" msg="">
    <preCondition id="1431523013533" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1431522912251</inState>
    <outState>#1431522995646</outState>
  </transitions>
  <transitions id="1431524869870" name="MISSING_NAME" comment="executed" msg="">
    <preCondition id="1431524871023" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1431522763494</inState>
    <outState>#1431524769489</outState>
  </transitions>
  <transitions id="1433949706015" name="MISSING_NAME" comment="aligned  and situation start" msg="">
    <preCondition id="1433949707598" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1433949667740</inState>
    <outState>#1431522155979</outState>
  </transitions>
  <transitions id="1435761866545" name="MISSING_NAME" comment="lostBall" msg="">
    <preCondition id="1435761870069" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1431522763494</inState>
    <outState>#1431522155979</outState>
  </transitions>
  <entryPoints id="1431522155980" name="StandardExecuter" comment="" successRequired="false" minCardinality="1" maxCardinality="1">
    <task>../../Misc/taskrepository.tsk#1238601692867</task>
    <state>#1433949667740</state>
  </entryPoints>
  <entryPoints id="1431522269326" name="StandardReceiver" comment="" successRequired="true" minCardinality="1" maxCardinality="1">
    <task>../../Misc/taskrepository.tsk#1238601842183</task>
    <state>#1431522297705</state>
  </entryPoints>
  <entryPoints id="1431523395534" name="Blocker" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1432209050494</task>
    <state>#1431523482646</state>
  </entryPoints>
  <entryPoints id="1431523422152" name="Defend" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1225115406909</task>
    <state>#1431524014799</state>
  </entryPoints>
</alica:Plan>