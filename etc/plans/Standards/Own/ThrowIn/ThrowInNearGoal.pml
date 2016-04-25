<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1461237603689" name="ThrowInNearGoal" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="" priority="0.0" minCardinality="0" maxCardinality="4">
  <conditions xsi:type="alica:RuntimeCondition" id="1461574228077" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin"/>
  <states id="1461237603690" name="Align" comment="" entryPoint="1461237603691">
    <outTransitions>#1461237656318</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1461237614163" name="Success" comment="">
    <inTransitions>#1461237853423</inTransitions>
  </states>
  <states id="1461237638988" name="GrabBall" comment="">
    <inTransitions>#1461237656318</inTransitions>
    <outTransitions>#1461237676305</outTransitions>
  </states>
  <states id="1461237666032" name="Pass" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../../../GenericStandards/StandardPass.beh#1435760175843</plans>
    <plans xsi:type="alica:BehaviourConfiguration">../../../GenericStandards/StandardActuate.beh#1435766278023</plans>
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/ShovelSelect.beh#1435156714286</plans>
    <inTransitions>#1461237676305</inTransitions>
  </states>
  <states id="1461237695900" name="Align" comment="" entryPoint="1461237744256">
    <outTransitions>#1461572769511</outTransitions>
  </states>
  <states id="1461237704581" name="Receive" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/ShovelSelect.beh#1435156811453</plans>
    <inTransitions>#1461572769511</inTransitions>
    <outTransitions>#1461237853423</outTransitions>
  </states>
  <states id="1461237711590" name="Block" comment="" entryPoint="1461237746825">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/Pos4Def.beh#1445438204426</plans>
  </states>
  <states id="1461237728343" name="Attack" comment="" entryPoint="1461237748826">
    <plans xsi:type="alica:BehaviourConfiguration">../../../Behaviours/PosAttacker.beh#1461574297571</plans>
  </states>
  <transitions id="1461237656318" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1461237657374" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1461237603690</inState>
    <outState>#1461237638988</outState>
  </transitions>
  <transitions id="1461237676305" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1461237677283" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1461237638988</inState>
    <outState>#1461237666032</outState>
  </transitions>
  <transitions id="1461237853423" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1461237854702" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1461237704581</inState>
    <outState>#1461237614163</outState>
  </transitions>
  <transitions id="1461572769511" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1461572770571" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1461237695900</inState>
    <outState>#1461237704581</outState>
  </transitions>
  <entryPoints id="1461237603691" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="1">
    <task>../../../../Misc/taskrepository.tsk#1461237758612</task>
    <state>#1461237603690</state>
  </entryPoints>
  <entryPoints id="1461237744256" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="1">
    <task>../../../../Misc/taskrepository.tsk#1461237762868</task>
    <state>#1461237695900</state>
  </entryPoints>
  <entryPoints id="1461237746825" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="1">
    <task>../../../../Misc/taskrepository.tsk#1461237765109</task>
    <state>#1461237711590</state>
  </entryPoints>
  <entryPoints id="1461237748826" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="1">
    <task>../../../../Misc/taskrepository.tsk#1461237767246</task>
    <state>#1461237728343</state>
  </entryPoints>
</alica:Plan>
