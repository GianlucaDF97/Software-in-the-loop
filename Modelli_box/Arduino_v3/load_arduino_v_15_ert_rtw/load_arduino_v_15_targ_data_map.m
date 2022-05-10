  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 18;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (load_arduino_v_15_P)
    ;%
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Kd_h_app
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Kd_h_flare
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.Ki_h_app
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.Ki_h_cruise
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.Ki_h_flare
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.Kp_AP_quota_hold_h
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_P.Kp_AP_quota_hold_l
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_P.Kp_Rotta_ATO
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_P.Kp_Rotta_psi
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_P.Kp_comp_h
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_P.Kp_h_cruise
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_P.Kp_h_flare
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_P.V_max
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_P.V_stall
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_P.attuatore_Amax
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_P.attuatore_Amin
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_P.attuatore_Emax
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_P.attuatore_Emin
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_P.attuatore_Rmax
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_P.attuatore_Rmin
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_P.attuatore_Tmax
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_P.attuatore_Tmin
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_P.final_h
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_P.interventoA_05
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_P.interventoA_1
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_P.interventoE_05
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_P.interventoE_1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_P.interventoT
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_P.inv_A
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_P.inv_E
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_P.inv_R
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_P.inv_T
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_P.inv_comp_h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% load_arduino_v_15_P.safe_V
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_P.safe_phi
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% load_arduino_v_15_P.t_AP
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_P.theta_rot
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% load_arduino_v_15_P.time_alarm_SAFE
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% load_arduino_v_15_P.vel_wp1_al
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% load_arduino_v_15_P.vel_wp2_al
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Ki_AP_vel
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Ki_becch
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.Ki_roll
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.Kp_AP_rotta
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.Kp_AP_vel
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.Kp_becch
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_P.Kp_imb
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_P.Kp_p
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_P.Kp_q
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_P.Kp_roll
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.K_imb_inv
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 352;
      section.data(352)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.PIDController_InitialConditionF
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.PIDController1_InitialCondition
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.PIApproach_InitialConditionForF
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.PIApproach1_InitialConditionFor
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.PIDController_InitialConditio_l
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.PIDController1_InitialConditi_n
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_P.PIDController_InitialConditi_ld
	  section.data(7).logicalSrcIdx = 57;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_P.PIDController_InitialConditio_g
	  section.data(8).logicalSrcIdx = 58;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_P.PIRCsaturato_InitialConditionFo
	  section.data(9).logicalSrcIdx = 59;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_P.PIApproach_InitialConditionForI
	  section.data(10).logicalSrcIdx = 60;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_P.PIApproach1_InitialConditionF_n
	  section.data(11).logicalSrcIdx = 61;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_P.PIDController_InitialConditio_a
	  section.data(12).logicalSrcIdx = 62;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_P.PIDController_Kb
	  section.data(13).logicalSrcIdx = 63;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_P.PIDController_Kb_g
	  section.data(14).logicalSrcIdx = 64;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_P.PIDController_Kt
	  section.data(15).logicalSrcIdx = 65;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_P.PIApproach_Kt
	  section.data(16).logicalSrcIdx = 66;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_P.PIApproach1_Kt
	  section.data(17).logicalSrcIdx = 67;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_P.PIRCsaturato_Kt
	  section.data(18).logicalSrcIdx = 68;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_P.PIDController_Kt_p
	  section.data(19).logicalSrcIdx = 69;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_P.PIDController_Kt_g
	  section.data(20).logicalSrcIdx = 70;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_P.PIDController1_Kt
	  section.data(21).logicalSrcIdx = 71;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_P.PIDController1_LowerSaturationL
	  section.data(22).logicalSrcIdx = 72;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_P.PIDController1_UpperSaturationL
	  section.data(23).logicalSrcIdx = 73;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_P.CompareToConstant_const
	  section.data(24).logicalSrcIdx = 74;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_P.CompareToConstant_const_h
	  section.data(25).logicalSrcIdx = 75;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_P.CompareToConstant_const_f
	  section.data(26).logicalSrcIdx = 76;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_P.CompareToConstant_const_k
	  section.data(27).logicalSrcIdx = 77;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_P.CompareToConstant_const_m
	  section.data(28).logicalSrcIdx = 78;
	  section.data(28).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_P.CompareToConstant_const_o
	  section.data(29).logicalSrcIdx = 79;
	  section.data(29).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_P.SerialTransmit_Protocol
	  section.data(30).logicalSrcIdx = 80;
	  section.data(30).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_P.Constant2_Value
	  section.data(31).logicalSrcIdx = 81;
	  section.data(31).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_P.nDLookupTable_tableData
	  section.data(32).logicalSrcIdx = 82;
	  section.data(32).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_P.nDLookupTable_bp01Data
	  section.data(33).logicalSrcIdx = 83;
	  section.data(33).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_P.LookupTable2_XData
	  section.data(34).logicalSrcIdx = 84;
	  section.data(34).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_P.LookupTable2_YData
	  section.data(35).logicalSrcIdx = 85;
	  section.data(35).dtTransOffset = 41;
	
	  ;% load_arduino_v_15_P.Constant4_Value
	  section.data(36).logicalSrcIdx = 86;
	  section.data(36).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_P.Switch_Threshold
	  section.data(37).logicalSrcIdx = 87;
	  section.data(37).dtTransOffset = 48;
	
	  ;% load_arduino_v_15_P.Out1_Y0
	  section.data(38).logicalSrcIdx = 88;
	  section.data(38).dtTransOffset = 49;
	
	  ;% load_arduino_v_15_P.Constant_Value
	  section.data(39).logicalSrcIdx = 89;
	  section.data(39).dtTransOffset = 50;
	
	  ;% load_arduino_v_15_P.Constant3_Value
	  section.data(40).logicalSrcIdx = 90;
	  section.data(40).dtTransOffset = 51;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_k
	  section.data(41).logicalSrcIdx = 91;
	  section.data(41).dtTransOffset = 52;
	
	  ;% load_arduino_v_15_P.Constant2_Value_f
	  section.data(42).logicalSrcIdx = 92;
	  section.data(42).dtTransOffset = 53;
	
	  ;% load_arduino_v_15_P.Constant2_Value_c
	  section.data(43).logicalSrcIdx = 93;
	  section.data(43).dtTransOffset = 54;
	
	  ;% load_arduino_v_15_P.Gain_Gain
	  section.data(44).logicalSrcIdx = 94;
	  section.data(44).dtTransOffset = 55;
	
	  ;% load_arduino_v_15_P.Gain_Gain_i
	  section.data(45).logicalSrcIdx = 95;
	  section.data(45).dtTransOffset = 56;
	
	  ;% load_arduino_v_15_P.Constant5_Value
	  section.data(46).logicalSrcIdx = 96;
	  section.data(46).dtTransOffset = 57;
	
	  ;% load_arduino_v_15_P.Constant2_Value_o
	  section.data(47).logicalSrcIdx = 97;
	  section.data(47).dtTransOffset = 58;
	
	  ;% load_arduino_v_15_P.Constant2_Value_b
	  section.data(48).logicalSrcIdx = 98;
	  section.data(48).dtTransOffset = 59;
	
	  ;% load_arduino_v_15_P.Gain_Gain_b
	  section.data(49).logicalSrcIdx = 99;
	  section.data(49).dtTransOffset = 60;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold
	  section.data(50).logicalSrcIdx = 100;
	  section.data(50).dtTransOffset = 61;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_i
	  section.data(51).logicalSrcIdx = 101;
	  section.data(51).dtTransOffset = 62;
	
	  ;% load_arduino_v_15_P.Switch3_Threshold
	  section.data(52).logicalSrcIdx = 102;
	  section.data(52).dtTransOffset = 63;
	
	  ;% load_arduino_v_15_P.Switch4_Threshold
	  section.data(53).logicalSrcIdx = 103;
	  section.data(53).dtTransOffset = 64;
	
	  ;% load_arduino_v_15_P.Gain1_Gain
	  section.data(54).logicalSrcIdx = 104;
	  section.data(54).dtTransOffset = 65;
	
	  ;% load_arduino_v_15_P.Constant1_Value
	  section.data(55).logicalSrcIdx = 105;
	  section.data(55).dtTransOffset = 66;
	
	  ;% load_arduino_v_15_P.Constant2_Value_k
	  section.data(56).logicalSrcIdx = 106;
	  section.data(56).dtTransOffset = 67;
	
	  ;% load_arduino_v_15_P.u0_Y0
	  section.data(57).logicalSrcIdx = 107;
	  section.data(57).dtTransOffset = 68;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_g
	  section.data(58).logicalSrcIdx = 108;
	  section.data(58).dtTransOffset = 69;
	
	  ;% load_arduino_v_15_P.Constant1_Value_e
	  section.data(59).logicalSrcIdx = 109;
	  section.data(59).dtTransOffset = 70;
	
	  ;% load_arduino_v_15_P.Constant2_Value_n
	  section.data(60).logicalSrcIdx = 110;
	  section.data(60).dtTransOffset = 71;
	
	  ;% load_arduino_v_15_P.u0_Y0_i
	  section.data(61).logicalSrcIdx = 111;
	  section.data(61).dtTransOffset = 72;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_g1
	  section.data(62).logicalSrcIdx = 112;
	  section.data(62).dtTransOffset = 73;
	
	  ;% load_arduino_v_15_P.Alarm_Int_Y0
	  section.data(63).logicalSrcIdx = 113;
	  section.data(63).dtTransOffset = 74;
	
	  ;% load_arduino_v_15_P.Alarm_Int_Y0_j
	  section.data(64).logicalSrcIdx = 114;
	  section.data(64).dtTransOffset = 75;
	
	  ;% load_arduino_v_15_P.Constant_Value_h
	  section.data(65).logicalSrcIdx = 115;
	  section.data(65).dtTransOffset = 76;
	
	  ;% load_arduino_v_15_P.Constant1_Value_i
	  section.data(66).logicalSrcIdx = 116;
	  section.data(66).dtTransOffset = 77;
	
	  ;% load_arduino_v_15_P.AlarmSafe_Y0
	  section.data(67).logicalSrcIdx = 117;
	  section.data(67).dtTransOffset = 78;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition
	  section.data(68).logicalSrcIdx = 118;
	  section.data(68).dtTransOffset = 79;
	
	  ;% load_arduino_v_15_P.Constant1_Value_d
	  section.data(69).logicalSrcIdx = 119;
	  section.data(69).dtTransOffset = 80;
	
	  ;% load_arduino_v_15_P.Gain_Gain_h
	  section.data(70).logicalSrcIdx = 120;
	  section.data(70).dtTransOffset = 81;
	
	  ;% load_arduino_v_15_P._Y0
	  section.data(71).logicalSrcIdx = 121;
	  section.data(71).dtTransOffset = 82;
	
	  ;% load_arduino_v_15_P._Y0_a
	  section.data(72).logicalSrcIdx = 122;
	  section.data(72).dtTransOffset = 83;
	
	  ;% load_arduino_v_15_P.rotta_ATO_Y0
	  section.data(73).logicalSrcIdx = 123;
	  section.data(73).dtTransOffset = 84;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition_k
	  section.data(74).logicalSrcIdx = 124;
	  section.data(74).dtTransOffset = 85;
	
	  ;% load_arduino_v_15_P.Gain_Gain_n
	  section.data(75).logicalSrcIdx = 125;
	  section.data(75).dtTransOffset = 86;
	
	  ;% load_arduino_v_15_P.Memory1_InitialCondition
	  section.data(76).logicalSrcIdx = 126;
	  section.data(76).dtTransOffset = 87;
	
	  ;% load_arduino_v_15_P.Gain_Gain_o
	  section.data(77).logicalSrcIdx = 127;
	  section.data(77).dtTransOffset = 88;
	
	  ;% load_arduino_v_15_P.Out1_Y0_f
	  section.data(78).logicalSrcIdx = 128;
	  section.data(78).dtTransOffset = 89;
	
	  ;% load_arduino_v_15_P.Out2_Y0
	  section.data(79).logicalSrcIdx = 129;
	  section.data(79).dtTransOffset = 90;
	
	  ;% load_arduino_v_15_P.Out3_Y0
	  section.data(80).logicalSrcIdx = 130;
	  section.data(80).dtTransOffset = 91;
	
	  ;% load_arduino_v_15_P.Out4_Y0
	  section.data(81).logicalSrcIdx = 131;
	  section.data(81).dtTransOffset = 92;
	
	  ;% load_arduino_v_15_P.Memory3_InitialCondition
	  section.data(82).logicalSrcIdx = 132;
	  section.data(82).dtTransOffset = 93;
	
	  ;% load_arduino_v_15_P.Gain_Gain_c
	  section.data(83).logicalSrcIdx = 133;
	  section.data(83).dtTransOffset = 94;
	
	  ;% load_arduino_v_15_P.h_ref_Y0
	  section.data(84).logicalSrcIdx = 134;
	  section.data(84).dtTransOffset = 95;
	
	  ;% load_arduino_v_15_P.flare_data_Y0
	  section.data(85).logicalSrcIdx = 135;
	  section.data(85).dtTransOffset = 96;
	
	  ;% load_arduino_v_15_P.landing_abort_Y0
	  section.data(86).logicalSrcIdx = 136;
	  section.data(86).dtTransOffset = 97;
	
	  ;% load_arduino_v_15_P.rc_ref_app_Y0
	  section.data(87).logicalSrcIdx = 137;
	  section.data(87).dtTransOffset = 98;
	
	  ;% load_arduino_v_15_P.x_g0_Value
	  section.data(88).logicalSrcIdx = 138;
	  section.data(88).dtTransOffset = 99;
	
	  ;% load_arduino_v_15_P.Constant3_Value_k
	  section.data(89).logicalSrcIdx = 139;
	  section.data(89).dtTransOffset = 100;
	
	  ;% load_arduino_v_15_P.Constant4_Value_e
	  section.data(90).logicalSrcIdx = 140;
	  section.data(90).dtTransOffset = 101;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_gainval
	  section.data(91).logicalSrcIdx = 141;
	  section.data(91).dtTransOffset = 102;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_IC
	  section.data(92).logicalSrcIdx = 142;
	  section.data(92).dtTransOffset = 103;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_UpperSat
	  section.data(93).logicalSrcIdx = 143;
	  section.data(93).dtTransOffset = 104;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_LowerSat
	  section.data(94).logicalSrcIdx = 144;
	  section.data(94).dtTransOffset = 105;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_a
	  section.data(95).logicalSrcIdx = 145;
	  section.data(95).dtTransOffset = 106;
	
	  ;% load_arduino_v_15_P.Gain_Gain_oz
	  section.data(96).logicalSrcIdx = 146;
	  section.data(96).dtTransOffset = 107;
	
	  ;% load_arduino_v_15_P.Constant2_Value_a
	  section.data(97).logicalSrcIdx = 147;
	  section.data(97).dtTransOffset = 108;
	
	  ;% load_arduino_v_15_P.h_ref_Y0_b
	  section.data(98).logicalSrcIdx = 148;
	  section.data(98).dtTransOffset = 109;
	
	  ;% load_arduino_v_15_P.RC_ref_Y0
	  section.data(99).logicalSrcIdx = 149;
	  section.data(99).dtTransOffset = 110;
	
	  ;% load_arduino_v_15_P.Gain_Gain_hs
	  section.data(100).logicalSrcIdx = 150;
	  section.data(100).dtTransOffset = 111;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_k
	  section.data(101).logicalSrcIdx = 151;
	  section.data(101).dtTransOffset = 112;
	
	  ;% load_arduino_v_15_P.Gain2_Gain
	  section.data(102).logicalSrcIdx = 152;
	  section.data(102).dtTransOffset = 113;
	
	  ;% load_arduino_v_15_P.psi_ref_landing_Y0
	  section.data(103).logicalSrcIdx = 153;
	  section.data(103).dtTransOffset = 114;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_e
	  section.data(104).logicalSrcIdx = 154;
	  section.data(104).dtTransOffset = 115;
	
	  ;% load_arduino_v_15_P.psirefgain2_Value
	  section.data(105).logicalSrcIdx = 155;
	  section.data(105).dtTransOffset = 116;
	
	  ;% load_arduino_v_15_P.Filter_gainval
	  section.data(106).logicalSrcIdx = 156;
	  section.data(106).dtTransOffset = 117;
	
	  ;% load_arduino_v_15_P.psirefgain3_Value
	  section.data(107).logicalSrcIdx = 157;
	  section.data(107).dtTransOffset = 118;
	
	  ;% load_arduino_v_15_P.Integrator_gainval
	  section.data(108).logicalSrcIdx = 158;
	  section.data(108).dtTransOffset = 119;
	
	  ;% load_arduino_v_15_P.psirefgain_Value
	  section.data(109).logicalSrcIdx = 159;
	  section.data(109).dtTransOffset = 120;
	
	  ;% load_arduino_v_15_P.Gain_Gain_l
	  section.data(110).logicalSrcIdx = 160;
	  section.data(110).dtTransOffset = 121;
	
	  ;% load_arduino_v_15_P.psirefgain1_Value
	  section.data(111).logicalSrcIdx = 161;
	  section.data(111).dtTransOffset = 122;
	
	  ;% load_arduino_v_15_P.Bias_Bias
	  section.data(112).logicalSrcIdx = 162;
	  section.data(112).dtTransOffset = 123;
	
	  ;% load_arduino_v_15_P.Gain_Gain_p
	  section.data(113).logicalSrcIdx = 163;
	  section.data(113).dtTransOffset = 124;
	
	  ;% load_arduino_v_15_P.Bias1_Bias
	  section.data(114).logicalSrcIdx = 164;
	  section.data(114).dtTransOffset = 125;
	
	  ;% load_arduino_v_15_P.Constant2_Value_o2
	  section.data(115).logicalSrcIdx = 165;
	  section.data(115).dtTransOffset = 126;
	
	  ;% load_arduino_v_15_P.Bias_Bias_d
	  section.data(116).logicalSrcIdx = 166;
	  section.data(116).dtTransOffset = 127;
	
	  ;% load_arduino_v_15_P.Bias1_Bias_j
	  section.data(117).logicalSrcIdx = 167;
	  section.data(117).dtTransOffset = 128;
	
	  ;% load_arduino_v_15_P.Constant_Value_e
	  section.data(118).logicalSrcIdx = 168;
	  section.data(118).dtTransOffset = 129;
	
	  ;% load_arduino_v_15_P.Constant1_Value_g
	  section.data(119).logicalSrcIdx = 169;
	  section.data(119).dtTransOffset = 130;
	
	  ;% load_arduino_v_15_P.Constant2_Value_on
	  section.data(120).logicalSrcIdx = 170;
	  section.data(120).dtTransOffset = 131;
	
	  ;% load_arduino_v_15_P.Bias_Bias_g
	  section.data(121).logicalSrcIdx = 171;
	  section.data(121).dtTransOffset = 132;
	
	  ;% load_arduino_v_15_P.Bias1_Bias_c
	  section.data(122).logicalSrcIdx = 172;
	  section.data(122).dtTransOffset = 133;
	
	  ;% load_arduino_v_15_P.Bias_Bias_m
	  section.data(123).logicalSrcIdx = 173;
	  section.data(123).dtTransOffset = 134;
	
	  ;% load_arduino_v_15_P.Gain_Gain_g
	  section.data(124).logicalSrcIdx = 174;
	  section.data(124).dtTransOffset = 135;
	
	  ;% load_arduino_v_15_P.Bias1_Bias_f
	  section.data(125).logicalSrcIdx = 175;
	  section.data(125).dtTransOffset = 136;
	
	  ;% load_arduino_v_15_P.Constant2_Value_e
	  section.data(126).logicalSrcIdx = 176;
	  section.data(126).dtTransOffset = 137;
	
	  ;% load_arduino_v_15_P.Bias_Bias_b
	  section.data(127).logicalSrcIdx = 177;
	  section.data(127).dtTransOffset = 138;
	
	  ;% load_arduino_v_15_P.Bias1_Bias_jg
	  section.data(128).logicalSrcIdx = 178;
	  section.data(128).dtTransOffset = 139;
	
	  ;% load_arduino_v_15_P.Constant_Value_a
	  section.data(129).logicalSrcIdx = 179;
	  section.data(129).dtTransOffset = 140;
	
	  ;% load_arduino_v_15_P.Constant1_Value_o
	  section.data(130).logicalSrcIdx = 180;
	  section.data(130).dtTransOffset = 141;
	
	  ;% load_arduino_v_15_P.Constant2_Value_j
	  section.data(131).logicalSrcIdx = 181;
	  section.data(131).dtTransOffset = 142;
	
	  ;% load_arduino_v_15_P.Bias_Bias_c
	  section.data(132).logicalSrcIdx = 182;
	  section.data(132).dtTransOffset = 143;
	
	  ;% load_arduino_v_15_P.Bias1_Bias_g
	  section.data(133).logicalSrcIdx = 183;
	  section.data(133).dtTransOffset = 144;
	
	  ;% load_arduino_v_15_P._Y0_f
	  section.data(134).logicalSrcIdx = 184;
	  section.data(134).dtTransOffset = 145;
	
	  ;% load_arduino_v_15_P.Constant3_Value_m
	  section.data(135).logicalSrcIdx = 185;
	  section.data(135).dtTransOffset = 147;
	
	  ;% load_arduino_v_15_P.Constant8_Value
	  section.data(136).logicalSrcIdx = 186;
	  section.data(136).dtTransOffset = 148;
	
	  ;% load_arduino_v_15_P.TAS_AL_Y0
	  section.data(137).logicalSrcIdx = 187;
	  section.data(137).dtTransOffset = 149;
	
	  ;% load_arduino_v_15_P.QUOTA_AL_Y0
	  section.data(138).logicalSrcIdx = 188;
	  section.data(138).dtTransOffset = 150;
	
	  ;% load_arduino_v_15_P.RC_AL_Y0
	  section.data(139).logicalSrcIdx = 189;
	  section.data(139).dtTransOffset = 151;
	
	  ;% load_arduino_v_15_P.ROTTA_AL_Y0
	  section.data(140).logicalSrcIdx = 190;
	  section.data(140).dtTransOffset = 152;
	
	  ;% load_arduino_v_15_P.distancewaypointsvirtuale_Value
	  section.data(141).logicalSrcIdx = 191;
	  section.data(141).dtTransOffset = 153;
	
	  ;% load_arduino_v_15_P.Gain_Gain_m
	  section.data(142).logicalSrcIdx = 192;
	  section.data(142).dtTransOffset = 156;
	
	  ;% load_arduino_v_15_P.Gain_Gain_pc
	  section.data(143).logicalSrcIdx = 193;
	  section.data(143).dtTransOffset = 157;
	
	  ;% load_arduino_v_15_P.altwaypointvirtuale_Value
	  section.data(144).logicalSrcIdx = 194;
	  section.data(144).dtTransOffset = 158;
	
	  ;% load_arduino_v_15_P.Gain_Gain_j
	  section.data(145).logicalSrcIdx = 195;
	  section.data(145).dtTransOffset = 161;
	
	  ;% load_arduino_v_15_P.Gain_Gain_d
	  section.data(146).logicalSrcIdx = 196;
	  section.data(146).dtTransOffset = 162;
	
	  ;% load_arduino_v_15_P.Gain_Gain_n2
	  section.data(147).logicalSrcIdx = 197;
	  section.data(147).dtTransOffset = 163;
	
	  ;% load_arduino_v_15_P.Gain_Gain_k
	  section.data(148).logicalSrcIdx = 198;
	  section.data(148).dtTransOffset = 164;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_m
	  section.data(149).logicalSrcIdx = 199;
	  section.data(149).dtTransOffset = 165;
	
	  ;% load_arduino_v_15_P.Constant2_Value_oc
	  section.data(150).logicalSrcIdx = 200;
	  section.data(150).dtTransOffset = 166;
	
	  ;% load_arduino_v_15_P.Constant_Value_l
	  section.data(151).logicalSrcIdx = 201;
	  section.data(151).dtTransOffset = 167;
	
	  ;% load_arduino_v_15_P.Constant4_Value_ee
	  section.data(152).logicalSrcIdx = 202;
	  section.data(152).dtTransOffset = 168;
	
	  ;% load_arduino_v_15_P.Constant_Value_i
	  section.data(153).logicalSrcIdx = 203;
	  section.data(153).dtTransOffset = 169;
	
	  ;% load_arduino_v_15_P.f_Value
	  section.data(154).logicalSrcIdx = 204;
	  section.data(154).dtTransOffset = 170;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_m4
	  section.data(155).logicalSrcIdx = 205;
	  section.data(155).dtTransOffset = 171;
	
	  ;% load_arduino_v_15_P.Constant1_Value_n
	  section.data(156).logicalSrcIdx = 206;
	  section.data(156).dtTransOffset = 172;
	
	  ;% load_arduino_v_15_P.Constant_Value_b
	  section.data(157).logicalSrcIdx = 207;
	  section.data(157).dtTransOffset = 173;
	
	  ;% load_arduino_v_15_P.Constant3_Value_h
	  section.data(158).logicalSrcIdx = 208;
	  section.data(158).dtTransOffset = 174;
	
	  ;% load_arduino_v_15_P.Gain_Gain_lp
	  section.data(159).logicalSrcIdx = 209;
	  section.data(159).dtTransOffset = 175;
	
	  ;% load_arduino_v_15_P.Gain_Gain_iz
	  section.data(160).logicalSrcIdx = 210;
	  section.data(160).dtTransOffset = 176;
	
	  ;% load_arduino_v_15_P.Gain_Gain_dl
	  section.data(161).logicalSrcIdx = 211;
	  section.data(161).dtTransOffset = 177;
	
	  ;% load_arduino_v_15_P.Memory7_InitialCondition
	  section.data(162).logicalSrcIdx = 212;
	  section.data(162).dtTransOffset = 178;
	
	  ;% load_arduino_v_15_P.Memory5_InitialCondition
	  section.data(163).logicalSrcIdx = 213;
	  section.data(163).dtTransOffset = 179;
	
	  ;% load_arduino_v_15_P.Memory1_InitialCondition_g
	  section.data(164).logicalSrcIdx = 214;
	  section.data(164).dtTransOffset = 180;
	
	  ;% load_arduino_v_15_P.Memory2_InitialCondition
	  section.data(165).logicalSrcIdx = 215;
	  section.data(165).dtTransOffset = 181;
	
	  ;% load_arduino_v_15_P.Constant4_Value_n
	  section.data(166).logicalSrcIdx = 216;
	  section.data(166).dtTransOffset = 182;
	
	  ;% load_arduino_v_15_P.Constant1_Value_c
	  section.data(167).logicalSrcIdx = 217;
	  section.data(167).dtTransOffset = 183;
	
	  ;% load_arduino_v_15_P.Constant7_Value
	  section.data(168).logicalSrcIdx = 218;
	  section.data(168).dtTransOffset = 184;
	
	  ;% load_arduino_v_15_P.Constant2_Value_jb
	  section.data(169).logicalSrcIdx = 219;
	  section.data(169).dtTransOffset = 185;
	
	  ;% load_arduino_v_15_P.latezzacarrello_Value
	  section.data(170).logicalSrcIdx = 220;
	  section.data(170).dtTransOffset = 186;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_p
	  section.data(171).logicalSrcIdx = 221;
	  section.data(171).dtTransOffset = 187;
	
	  ;% load_arduino_v_15_P.Switch1_Threshold
	  section.data(172).logicalSrcIdx = 222;
	  section.data(172).dtTransOffset = 188;
	
	  ;% load_arduino_v_15_P.RC_Y0
	  section.data(173).logicalSrcIdx = 223;
	  section.data(173).dtTransOffset = 189;
	
	  ;% load_arduino_v_15_P.VELOCITA_Y0
	  section.data(174).logicalSrcIdx = 224;
	  section.data(174).dtTransOffset = 190;
	
	  ;% load_arduino_v_15_P.Out3_Y0_j
	  section.data(175).logicalSrcIdx = 225;
	  section.data(175).dtTransOffset = 191;
	
	  ;% load_arduino_v_15_P.Out4_Y0_e
	  section.data(176).logicalSrcIdx = 226;
	  section.data(176).dtTransOffset = 192;
	
	  ;% load_arduino_v_15_P.Memory4_InitialCondition
	  section.data(177).logicalSrcIdx = 227;
	  section.data(177).dtTransOffset = 193;
	
	  ;% load_arduino_v_15_P.Gain_Gain_hq
	  section.data(178).logicalSrcIdx = 228;
	  section.data(178).dtTransOffset = 194;
	
	  ;% load_arduino_v_15_P.Gain_Gain_jr
	  section.data(179).logicalSrcIdx = 229;
	  section.data(179).dtTransOffset = 195;
	
	  ;% load_arduino_v_15_P.Gain_Gain_l2
	  section.data(180).logicalSrcIdx = 230;
	  section.data(180).dtTransOffset = 196;
	
	  ;% load_arduino_v_15_P.saturatoreV_UpperSat
	  section.data(181).logicalSrcIdx = 231;
	  section.data(181).dtTransOffset = 197;
	
	  ;% load_arduino_v_15_P.saturatoreV_LowerSat
	  section.data(182).logicalSrcIdx = 232;
	  section.data(182).dtTransOffset = 198;
	
	  ;% load_arduino_v_15_P.saturatoreV1_UpperSat
	  section.data(183).logicalSrcIdx = 233;
	  section.data(183).dtTransOffset = 199;
	
	  ;% load_arduino_v_15_P.saturatoreV1_LowerSat
	  section.data(184).logicalSrcIdx = 234;
	  section.data(184).dtTransOffset = 200;
	
	  ;% load_arduino_v_15_P.Out1_Y0_j
	  section.data(185).logicalSrcIdx = 235;
	  section.data(185).dtTransOffset = 201;
	
	  ;% load_arduino_v_15_P.Out2_Y0_n
	  section.data(186).logicalSrcIdx = 236;
	  section.data(186).dtTransOffset = 202;
	
	  ;% load_arduino_v_15_P.Out3_Y0_e
	  section.data(187).logicalSrcIdx = 237;
	  section.data(187).dtTransOffset = 203;
	
	  ;% load_arduino_v_15_P.Out4_Y0_n
	  section.data(188).logicalSrcIdx = 238;
	  section.data(188).dtTransOffset = 204;
	
	  ;% load_arduino_v_15_P.Gain_Gain_jv
	  section.data(189).logicalSrcIdx = 239;
	  section.data(189).dtTransOffset = 205;
	
	  ;% load_arduino_v_15_P.Gain_Gain_hc
	  section.data(190).logicalSrcIdx = 240;
	  section.data(190).dtTransOffset = 206;
	
	  ;% load_arduino_v_15_P.Gain_Gain_pr
	  section.data(191).logicalSrcIdx = 241;
	  section.data(191).dtTransOffset = 207;
	
	  ;% load_arduino_v_15_P.SerialReceive_Protocol
	  section.data(192).logicalSrcIdx = 242;
	  section.data(192).dtTransOffset = 208;
	
	  ;% load_arduino_v_15_P.SerialTransmit_Protocol_b
	  section.data(193).logicalSrcIdx = 243;
	  section.data(193).dtTransOffset = 209;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_k
	  section.data(194).logicalSrcIdx = 244;
	  section.data(194).dtTransOffset = 210;
	
	  ;% load_arduino_v_15_P.Constant1_Value_ol
	  section.data(195).logicalSrcIdx = 245;
	  section.data(195).dtTransOffset = 211;
	
	  ;% load_arduino_v_15_P.Constant5_Value_n
	  section.data(196).logicalSrcIdx = 246;
	  section.data(196).dtTransOffset = 212;
	
	  ;% load_arduino_v_15_P.Constant6_Value
	  section.data(197).logicalSrcIdx = 247;
	  section.data(197).dtTransOffset = 213;
	
	  ;% load_arduino_v_15_P.Constant4_Value_l
	  section.data(198).logicalSrcIdx = 248;
	  section.data(198).dtTransOffset = 214;
	
	  ;% load_arduino_v_15_P.Constant2_Value_av
	  section.data(199).logicalSrcIdx = 249;
	  section.data(199).dtTransOffset = 215;
	
	  ;% load_arduino_v_15_P.Constant3_Value_c
	  section.data(200).logicalSrcIdx = 250;
	  section.data(200).dtTransOffset = 216;
	
	  ;% load_arduino_v_15_P.SerialReceive1_Protocol
	  section.data(201).logicalSrcIdx = 251;
	  section.data(201).dtTransOffset = 217;
	
	  ;% load_arduino_v_15_P.Constant2_Value_d
	  section.data(202).logicalSrcIdx = 252;
	  section.data(202).dtTransOffset = 218;
	
	  ;% load_arduino_v_15_P.h_to_subtract_Y0
	  section.data(203).logicalSrcIdx = 253;
	  section.data(203).dtTransOffset = 219;
	
	  ;% load_arduino_v_15_P.Constant_Value_lv
	  section.data(204).logicalSrcIdx = 254;
	  section.data(204).dtTransOffset = 220;
	
	  ;% load_arduino_v_15_P.Constant1_Value_b
	  section.data(205).logicalSrcIdx = 255;
	  section.data(205).dtTransOffset = 221;
	
	  ;% load_arduino_v_15_P.Constant3_Value_ct
	  section.data(206).logicalSrcIdx = 256;
	  section.data(206).dtTransOffset = 222;
	
	  ;% load_arduino_v_15_P.Outport_Y0
	  section.data(207).logicalSrcIdx = 257;
	  section.data(207).dtTransOffset = 223;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition_a
	  section.data(208).logicalSrcIdx = 258;
	  section.data(208).dtTransOffset = 224;
	
	  ;% load_arduino_v_15_P.Constant_Value_bh
	  section.data(209).logicalSrcIdx = 259;
	  section.data(209).dtTransOffset = 225;
	
	  ;% load_arduino_v_15_P.Constant1_Value_j
	  section.data(210).logicalSrcIdx = 260;
	  section.data(210).dtTransOffset = 226;
	
	  ;% load_arduino_v_15_P.Constant1_Value_op
	  section.data(211).logicalSrcIdx = 261;
	  section.data(211).dtTransOffset = 227;
	
	  ;% load_arduino_v_15_P.Constant1_Value_f
	  section.data(212).logicalSrcIdx = 262;
	  section.data(212).dtTransOffset = 228;
	
	  ;% load_arduino_v_15_P.Constant_Value_hx
	  section.data(213).logicalSrcIdx = 263;
	  section.data(213).dtTransOffset = 229;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_p
	  section.data(214).logicalSrcIdx = 264;
	  section.data(214).dtTransOffset = 230;
	
	  ;% load_arduino_v_15_P.Gain4_Gain
	  section.data(215).logicalSrcIdx = 265;
	  section.data(215).dtTransOffset = 231;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_kg
	  section.data(216).logicalSrcIdx = 266;
	  section.data(216).dtTransOffset = 232;
	
	  ;% load_arduino_v_15_P.Gain_Gain_mz
	  section.data(217).logicalSrcIdx = 267;
	  section.data(217).dtTransOffset = 233;
	
	  ;% load_arduino_v_15_P.Constant2_Value_kl
	  section.data(218).logicalSrcIdx = 268;
	  section.data(218).dtTransOffset = 234;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_j
	  section.data(219).logicalSrcIdx = 269;
	  section.data(219).dtTransOffset = 235;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_kd
	  section.data(220).logicalSrcIdx = 270;
	  section.data(220).dtTransOffset = 236;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_c
	  section.data(221).logicalSrcIdx = 271;
	  section.data(221).dtTransOffset = 237;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_kf
	  section.data(222).logicalSrcIdx = 272;
	  section.data(222).dtTransOffset = 238;
	
	  ;% load_arduino_v_15_P.Switch1_Threshold_c
	  section.data(223).logicalSrcIdx = 273;
	  section.data(223).dtTransOffset = 239;
	
	  ;% load_arduino_v_15_P.RateLimiter1_RisingLim
	  section.data(224).logicalSrcIdx = 274;
	  section.data(224).dtTransOffset = 240;
	
	  ;% load_arduino_v_15_P.RateLimiter1_FallingLim
	  section.data(225).logicalSrcIdx = 275;
	  section.data(225).dtTransOffset = 241;
	
	  ;% load_arduino_v_15_P.RateLimiter1_IC
	  section.data(226).logicalSrcIdx = 276;
	  section.data(226).dtTransOffset = 242;
	
	  ;% load_arduino_v_15_P.Constant1_Value_fs
	  section.data(227).logicalSrcIdx = 277;
	  section.data(227).dtTransOffset = 243;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_o
	  section.data(228).logicalSrcIdx = 278;
	  section.data(228).dtTransOffset = 244;
	
	  ;% load_arduino_v_15_P.RC_default_Value
	  section.data(229).logicalSrcIdx = 279;
	  section.data(229).dtTransOffset = 245;
	
	  ;% load_arduino_v_15_P.Constant_Value_g
	  section.data(230).logicalSrcIdx = 280;
	  section.data(230).dtTransOffset = 246;
	
	  ;% load_arduino_v_15_P.Constant1_Value_cc
	  section.data(231).logicalSrcIdx = 281;
	  section.data(231).dtTransOffset = 247;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_l
	  section.data(232).logicalSrcIdx = 282;
	  section.data(232).dtTransOffset = 248;
	
	  ;% load_arduino_v_15_P.Gain_Gain_pa
	  section.data(233).logicalSrcIdx = 283;
	  section.data(233).dtTransOffset = 249;
	
	  ;% load_arduino_v_15_P.Constant_Value_ig
	  section.data(234).logicalSrcIdx = 284;
	  section.data(234).dtTransOffset = 250;
	
	  ;% load_arduino_v_15_P.Constant1_Value_e3
	  section.data(235).logicalSrcIdx = 285;
	  section.data(235).dtTransOffset = 251;
	
	  ;% load_arduino_v_15_P.Constant2_Value_g
	  section.data(236).logicalSrcIdx = 286;
	  section.data(236).dtTransOffset = 252;
	
	  ;% load_arduino_v_15_P.Switch1_Threshold_b
	  section.data(237).logicalSrcIdx = 287;
	  section.data(237).dtTransOffset = 253;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_ef
	  section.data(238).logicalSrcIdx = 288;
	  section.data(238).dtTransOffset = 254;
	
	  ;% load_arduino_v_15_P.Switch3_Threshold_d
	  section.data(239).logicalSrcIdx = 289;
	  section.data(239).dtTransOffset = 255;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_h
	  section.data(240).logicalSrcIdx = 290;
	  section.data(240).dtTransOffset = 256;
	
	  ;% load_arduino_v_15_P.Switch4_Threshold_d
	  section.data(241).logicalSrcIdx = 291;
	  section.data(241).dtTransOffset = 257;
	
	  ;% load_arduino_v_15_P.Filter_gainval_d
	  section.data(242).logicalSrcIdx = 292;
	  section.data(242).dtTransOffset = 258;
	
	  ;% load_arduino_v_15_P.Constant_Value_j
	  section.data(243).logicalSrcIdx = 293;
	  section.data(243).dtTransOffset = 259;
	
	  ;% load_arduino_v_15_P.Constant_Value_a3
	  section.data(244).logicalSrcIdx = 294;
	  section.data(244).dtTransOffset = 260;
	
	  ;% load_arduino_v_15_P.Constant5_Value_g
	  section.data(245).logicalSrcIdx = 295;
	  section.data(245).dtTransOffset = 261;
	
	  ;% load_arduino_v_15_P.Constant3_Value_j
	  section.data(246).logicalSrcIdx = 296;
	  section.data(246).dtTransOffset = 262;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_i
	  section.data(247).logicalSrcIdx = 297;
	  section.data(247).dtTransOffset = 263;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_l
	  section.data(248).logicalSrcIdx = 298;
	  section.data(248).dtTransOffset = 264;
	
	  ;% load_arduino_v_15_P.HitCrossing_Offset
	  section.data(249).logicalSrcIdx = 299;
	  section.data(249).dtTransOffset = 265;
	
	  ;% load_arduino_v_15_P.Constant4_Value_d
	  section.data(250).logicalSrcIdx = 300;
	  section.data(250).dtTransOffset = 266;
	
	  ;% load_arduino_v_15_P.Constant8_Value_p
	  section.data(251).logicalSrcIdx = 301;
	  section.data(251).dtTransOffset = 267;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_gainva_p
	  section.data(252).logicalSrcIdx = 302;
	  section.data(252).dtTransOffset = 268;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_IC_e
	  section.data(253).logicalSrcIdx = 303;
	  section.data(253).dtTransOffset = 269;
	
	  ;% load_arduino_v_15_P.DiscreteTimeIntegrator_LowerS_o
	  section.data(254).logicalSrcIdx = 304;
	  section.data(254).dtTransOffset = 270;
	
	  ;% load_arduino_v_15_P.RateLimiter_RisingLim
	  section.data(255).logicalSrcIdx = 305;
	  section.data(255).dtTransOffset = 271;
	
	  ;% load_arduino_v_15_P.RateLimiter_FallingLim
	  section.data(256).logicalSrcIdx = 306;
	  section.data(256).dtTransOffset = 272;
	
	  ;% load_arduino_v_15_P.RateLimiter_IC
	  section.data(257).logicalSrcIdx = 307;
	  section.data(257).dtTransOffset = 273;
	
	  ;% load_arduino_v_15_P.DiscreteWashoutFilter_NumCoef
	  section.data(258).logicalSrcIdx = 308;
	  section.data(258).dtTransOffset = 274;
	
	  ;% load_arduino_v_15_P.DiscreteWashoutFilter_DenCoef
	  section.data(259).logicalSrcIdx = 309;
	  section.data(259).dtTransOffset = 276;
	
	  ;% load_arduino_v_15_P.DiscreteWashoutFilter_InitialSt
	  section.data(260).logicalSrcIdx = 310;
	  section.data(260).dtTransOffset = 278;
	
	  ;% load_arduino_v_15_P.r_rif_Value
	  section.data(261).logicalSrcIdx = 311;
	  section.data(261).dtTransOffset = 279;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_n
	  section.data(262).logicalSrcIdx = 312;
	  section.data(262).dtTransOffset = 280;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_m
	  section.data(263).logicalSrcIdx = 313;
	  section.data(263).dtTransOffset = 281;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_h
	  section.data(264).logicalSrcIdx = 314;
	  section.data(264).dtTransOffset = 282;
	
	  ;% load_arduino_v_15_P.Constant2_Value_em
	  section.data(265).logicalSrcIdx = 315;
	  section.data(265).dtTransOffset = 283;
	
	  ;% load_arduino_v_15_P.Constant1_Value_i3
	  section.data(266).logicalSrcIdx = 316;
	  section.data(266).dtTransOffset = 284;
	
	  ;% load_arduino_v_15_P.Constant2_Value_by
	  section.data(267).logicalSrcIdx = 317;
	  section.data(267).dtTransOffset = 285;
	
	  ;% load_arduino_v_15_P.Constant_Value_d
	  section.data(268).logicalSrcIdx = 318;
	  section.data(268).dtTransOffset = 286;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_hq
	  section.data(269).logicalSrcIdx = 319;
	  section.data(269).dtTransOffset = 287;
	
	  ;% load_arduino_v_15_P.Constant1_Value_l
	  section.data(270).logicalSrcIdx = 320;
	  section.data(270).dtTransOffset = 288;
	
	  ;% load_arduino_v_15_P.nDLookupTable_tableData_c
	  section.data(271).logicalSrcIdx = 321;
	  section.data(271).dtTransOffset = 289;
	
	  ;% load_arduino_v_15_P.nDLookupTable_bp01Data_l
	  section.data(272).logicalSrcIdx = 322;
	  section.data(272).dtTransOffset = 291;
	
	  ;% load_arduino_v_15_P.Saturation_UpperSat
	  section.data(273).logicalSrcIdx = 323;
	  section.data(273).dtTransOffset = 293;
	
	  ;% load_arduino_v_15_P.Saturation_LowerSat
	  section.data(274).logicalSrcIdx = 324;
	  section.data(274).dtTransOffset = 294;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_f
	  section.data(275).logicalSrcIdx = 325;
	  section.data(275).dtTransOffset = 295;
	
	  ;% load_arduino_v_15_P.Filter_gainval_a
	  section.data(276).logicalSrcIdx = 326;
	  section.data(276).dtTransOffset = 296;
	
	  ;% load_arduino_v_15_P.Constant15_Value
	  section.data(277).logicalSrcIdx = 327;
	  section.data(277).dtTransOffset = 297;
	
	  ;% load_arduino_v_15_P.Constant3_Value_f
	  section.data(278).logicalSrcIdx = 328;
	  section.data(278).dtTransOffset = 298;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_p
	  section.data(279).logicalSrcIdx = 329;
	  section.data(279).dtTransOffset = 299;
	
	  ;% load_arduino_v_15_P.Filter_gainval_d1
	  section.data(280).logicalSrcIdx = 330;
	  section.data(280).dtTransOffset = 300;
	
	  ;% load_arduino_v_15_P.Constant13_Value
	  section.data(281).logicalSrcIdx = 331;
	  section.data(281).dtTransOffset = 301;
	
	  ;% load_arduino_v_15_P.Constant_Value_at
	  section.data(282).logicalSrcIdx = 332;
	  section.data(282).dtTransOffset = 302;
	
	  ;% load_arduino_v_15_P.Integrator_gainval_e
	  section.data(283).logicalSrcIdx = 333;
	  section.data(283).dtTransOffset = 303;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_l
	  section.data(284).logicalSrcIdx = 334;
	  section.data(284).dtTransOffset = 304;
	
	  ;% load_arduino_v_15_P.RateTransition_InitialCondition
	  section.data(285).logicalSrcIdx = 335;
	  section.data(285).dtTransOffset = 305;
	
	  ;% load_arduino_v_15_P.Constant2_Value_jg
	  section.data(286).logicalSrcIdx = 336;
	  section.data(286).dtTransOffset = 306;
	
	  ;% load_arduino_v_15_P.Constant3_Value_o
	  section.data(287).logicalSrcIdx = 337;
	  section.data(287).dtTransOffset = 307;
	
	  ;% load_arduino_v_15_P.Memory1_InitialCondition_p
	  section.data(288).logicalSrcIdx = 338;
	  section.data(288).dtTransOffset = 308;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_f
	  section.data(289).logicalSrcIdx = 339;
	  section.data(289).dtTransOffset = 309;
	
	  ;% load_arduino_v_15_P.Constant_Value_m
	  section.data(290).logicalSrcIdx = 340;
	  section.data(290).dtTransOffset = 310;
	
	  ;% load_arduino_v_15_P.Constant1_Value_n0
	  section.data(291).logicalSrcIdx = 341;
	  section.data(291).dtTransOffset = 311;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition_au
	  section.data(292).logicalSrcIdx = 342;
	  section.data(292).dtTransOffset = 312;
	
	  ;% load_arduino_v_15_P.Gain_Gain_cw
	  section.data(293).logicalSrcIdx = 343;
	  section.data(293).dtTransOffset = 313;
	
	  ;% load_arduino_v_15_P.Constant_Value_jp
	  section.data(294).logicalSrcIdx = 344;
	  section.data(294).dtTransOffset = 314;
	
	  ;% load_arduino_v_15_P.Gain_Gain_by
	  section.data(295).logicalSrcIdx = 345;
	  section.data(295).dtTransOffset = 317;
	
	  ;% load_arduino_v_15_P.Gain2_Gain_o
	  section.data(296).logicalSrcIdx = 346;
	  section.data(296).dtTransOffset = 318;
	
	  ;% load_arduino_v_15_P.Constant_Value_ex
	  section.data(297).logicalSrcIdx = 347;
	  section.data(297).dtTransOffset = 319;
	
	  ;% load_arduino_v_15_P.Constant_Value_hxg
	  section.data(298).logicalSrcIdx = 348;
	  section.data(298).dtTransOffset = 320;
	
	  ;% load_arduino_v_15_P.Constant1_Value_fi
	  section.data(299).logicalSrcIdx = 349;
	  section.data(299).dtTransOffset = 321;
	
	  ;% load_arduino_v_15_P.Constant2_Value_eu
	  section.data(300).logicalSrcIdx = 350;
	  section.data(300).dtTransOffset = 322;
	
	  ;% load_arduino_v_15_P.Gain_Gain_dn
	  section.data(301).logicalSrcIdx = 351;
	  section.data(301).dtTransOffset = 323;
	
	  ;% load_arduino_v_15_P.Gain_Gain_f
	  section.data(302).logicalSrcIdx = 352;
	  section.data(302).dtTransOffset = 324;
	
	  ;% load_arduino_v_15_P.Gain_Gain_ds
	  section.data(303).logicalSrcIdx = 353;
	  section.data(303).dtTransOffset = 325;
	
	  ;% load_arduino_v_15_P.alt_r_Value
	  section.data(304).logicalSrcIdx = 354;
	  section.data(304).dtTransOffset = 326;
	
	  ;% load_arduino_v_15_P.Gain_Gain_bx
	  section.data(305).logicalSrcIdx = 355;
	  section.data(305).dtTransOffset = 327;
	
	  ;% load_arduino_v_15_P.vely_Value
	  section.data(306).logicalSrcIdx = 356;
	  section.data(306).dtTransOffset = 331;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_ej
	  section.data(307).logicalSrcIdx = 357;
	  section.data(307).dtTransOffset = 332;
	
	  ;% load_arduino_v_15_P.Gain2_Gain_k
	  section.data(308).logicalSrcIdx = 358;
	  section.data(308).dtTransOffset = 333;
	
	  ;% load_arduino_v_15_P.Gain_Gain_lb
	  section.data(309).logicalSrcIdx = 359;
	  section.data(309).dtTransOffset = 334;
	
	  ;% load_arduino_v_15_P.Switch2_Threshold_a
	  section.data(310).logicalSrcIdx = 360;
	  section.data(310).dtTransOffset = 335;
	
	  ;% load_arduino_v_15_P.Constant_Value_c
	  section.data(311).logicalSrcIdx = 361;
	  section.data(311).dtTransOffset = 336;
	
	  ;% load_arduino_v_15_P.USCITAPERCENTUALE_Gain
	  section.data(312).logicalSrcIdx = 362;
	  section.data(312).dtTransOffset = 337;
	
	  ;% load_arduino_v_15_P.Constant_Value_bh2
	  section.data(313).logicalSrcIdx = 363;
	  section.data(313).dtTransOffset = 338;
	
	  ;% load_arduino_v_15_P.Gain2_Gain_j
	  section.data(314).logicalSrcIdx = 364;
	  section.data(314).dtTransOffset = 339;
	
	  ;% load_arduino_v_15_P.Gain_Gain_od
	  section.data(315).logicalSrcIdx = 365;
	  section.data(315).dtTransOffset = 340;
	
	  ;% load_arduino_v_15_P.Constant2_Value_m
	  section.data(316).logicalSrcIdx = 366;
	  section.data(316).dtTransOffset = 341;
	
	  ;% load_arduino_v_15_P.Gain_Gain_if
	  section.data(317).logicalSrcIdx = 367;
	  section.data(317).dtTransOffset = 342;
	
	  ;% load_arduino_v_15_P.Gain_Gain_bh
	  section.data(318).logicalSrcIdx = 368;
	  section.data(318).dtTransOffset = 343;
	
	  ;% load_arduino_v_15_P.Constant1_Value_p
	  section.data(319).logicalSrcIdx = 369;
	  section.data(319).dtTransOffset = 344;
	
	  ;% load_arduino_v_15_P.Gain_Gain_jrt
	  section.data(320).logicalSrcIdx = 370;
	  section.data(320).dtTransOffset = 347;
	
	  ;% load_arduino_v_15_P.Saturation_UpperSat_a
	  section.data(321).logicalSrcIdx = 371;
	  section.data(321).dtTransOffset = 348;
	
	  ;% load_arduino_v_15_P.Saturation_LowerSat_p
	  section.data(322).logicalSrcIdx = 372;
	  section.data(322).dtTransOffset = 349;
	
	  ;% load_arduino_v_15_P.DelayInput2_InitialCondition
	  section.data(323).logicalSrcIdx = 373;
	  section.data(323).dtTransOffset = 350;
	
	  ;% load_arduino_v_15_P.sampletime_WtEt
	  section.data(324).logicalSrcIdx = 374;
	  section.data(324).dtTransOffset = 351;
	
	  ;% load_arduino_v_15_P.PatohPa_Gain
	  section.data(325).logicalSrcIdx = 375;
	  section.data(325).dtTransOffset = 352;
	
	  ;% load_arduino_v_15_P.Gain7_Gain
	  section.data(326).logicalSrcIdx = 376;
	  section.data(326).dtTransOffset = 353;
	
	  ;% load_arduino_v_15_P.PatohPa1_Gain
	  section.data(327).logicalSrcIdx = 377;
	  section.data(327).dtTransOffset = 354;
	
	  ;% load_arduino_v_15_P.Gain_Gain_nk
	  section.data(328).logicalSrcIdx = 378;
	  section.data(328).dtTransOffset = 355;
	
	  ;% load_arduino_v_15_P.Gain_Gain_db
	  section.data(329).logicalSrcIdx = 379;
	  section.data(329).dtTransOffset = 356;
	
	  ;% load_arduino_v_15_P.Gain_Gain_dc
	  section.data(330).logicalSrcIdx = 380;
	  section.data(330).dtTransOffset = 357;
	
	  ;% load_arduino_v_15_P.Gain_Gain_bk
	  section.data(331).logicalSrcIdx = 381;
	  section.data(331).dtTransOffset = 358;
	
	  ;% load_arduino_v_15_P.Gain2_Gain_m
	  section.data(332).logicalSrcIdx = 382;
	  section.data(332).dtTransOffset = 359;
	
	  ;% load_arduino_v_15_P.Gain3_Gain
	  section.data(333).logicalSrcIdx = 383;
	  section.data(333).dtTransOffset = 360;
	
	  ;% load_arduino_v_15_P.Constant1_Value_fu
	  section.data(334).logicalSrcIdx = 384;
	  section.data(334).dtTransOffset = 361;
	
	  ;% load_arduino_v_15_P.Gain6_Gain
	  section.data(335).logicalSrcIdx = 385;
	  section.data(335).dtTransOffset = 362;
	
	  ;% load_arduino_v_15_P.Gain_Gain_je
	  section.data(336).logicalSrcIdx = 386;
	  section.data(336).dtTransOffset = 363;
	
	  ;% load_arduino_v_15_P.ZeroGain_Gain
	  section.data(337).logicalSrcIdx = 387;
	  section.data(337).dtTransOffset = 364;
	
	  ;% load_arduino_v_15_P.Constant2_Value_kv
	  section.data(338).logicalSrcIdx = 388;
	  section.data(338).dtTransOffset = 365;
	
	  ;% load_arduino_v_15_P.ZeroGain_Gain_f
	  section.data(339).logicalSrcIdx = 389;
	  section.data(339).dtTransOffset = 366;
	
	  ;% load_arduino_v_15_P.Constant7_Value_i
	  section.data(340).logicalSrcIdx = 390;
	  section.data(340).dtTransOffset = 367;
	
	  ;% load_arduino_v_15_P.PulseGenerator_Amp
	  section.data(341).logicalSrcIdx = 391;
	  section.data(341).dtTransOffset = 368;
	
	  ;% load_arduino_v_15_P.PulseGenerator_Period
	  section.data(342).logicalSrcIdx = 392;
	  section.data(342).dtTransOffset = 369;
	
	  ;% load_arduino_v_15_P.PulseGenerator_Duty
	  section.data(343).logicalSrcIdx = 393;
	  section.data(343).dtTransOffset = 370;
	
	  ;% load_arduino_v_15_P.PulseGenerator_PhaseDelay
	  section.data(344).logicalSrcIdx = 394;
	  section.data(344).dtTransOffset = 371;
	
	  ;% load_arduino_v_15_P.PulseGenerator1_Amp
	  section.data(345).logicalSrcIdx = 395;
	  section.data(345).dtTransOffset = 372;
	
	  ;% load_arduino_v_15_P.PulseGenerator1_Period
	  section.data(346).logicalSrcIdx = 396;
	  section.data(346).dtTransOffset = 373;
	
	  ;% load_arduino_v_15_P.PulseGenerator1_Duty
	  section.data(347).logicalSrcIdx = 397;
	  section.data(347).dtTransOffset = 374;
	
	  ;% load_arduino_v_15_P.PulseGenerator1_PhaseDelay
	  section.data(348).logicalSrcIdx = 398;
	  section.data(348).dtTransOffset = 375;
	
	  ;% load_arduino_v_15_P.Constant4_Value_a
	  section.data(349).logicalSrcIdx = 399;
	  section.data(349).dtTransOffset = 376;
	
	  ;% load_arduino_v_15_P.Constant5_Value_a
	  section.data(350).logicalSrcIdx = 400;
	  section.data(350).dtTransOffset = 377;
	
	  ;% load_arduino_v_15_P.Memory2_InitialCondition_o
	  section.data(351).logicalSrcIdx = 401;
	  section.data(351).dtTransOffset = 378;
	
	  ;% load_arduino_v_15_P.Switch1_Threshold_ca
	  section.data(352).logicalSrcIdx = 402;
	  section.data(352).dtTransOffset = 379;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Constant_Value_gw
	  section.data(1).logicalSrcIdx = 403;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Out2_Y0_c
	  section.data(1).logicalSrcIdx = 404;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.T_Y0
	  section.data(2).logicalSrcIdx = 405;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.T_0_Y0
	  section.data(3).logicalSrcIdx = 406;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_p
	  section.data(4).logicalSrcIdx = 407;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.KiAProtta1_Value
	  section.data(5).logicalSrcIdx = 408;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.Gain5_Gain
	  section.data(6).logicalSrcIdx = 409;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.p_Y0
	  section.data(1).logicalSrcIdx = 410;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Constant7_Value_h
	  section.data(2).logicalSrcIdx = 411;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.Constant10_Value
	  section.data(3).logicalSrcIdx = 412;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.Constant11_Value
	  section.data(4).logicalSrcIdx = 413;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.Constant8_Value_e
	  section.data(5).logicalSrcIdx = 414;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.Constant9_Value
	  section.data(6).logicalSrcIdx = 415;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_P.onboard_control_sensor_presentu
	  section.data(7).logicalSrcIdx = 416;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Out3_Y0_a
	  section.data(1).logicalSrcIdx = 417;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Switch_Threshold_m
	  section.data(2).logicalSrcIdx = 418;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.Gain1_Gain_eu
	  section.data(3).logicalSrcIdx = 419;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Out4_Y0_i
	  section.data(1).logicalSrcIdx = 420;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition_at
	  section.data(2).logicalSrcIdx = 421;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.loaduint16_Value
	  section.data(3).logicalSrcIdx = 422;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P._Value
	  section.data(4).logicalSrcIdx = 423;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition_g
	  section.data(5).logicalSrcIdx = 424;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.UnitDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 425;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Constant3_Value_ok
	  section.data(2).logicalSrcIdx = 426;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.Memory_InitialCondition_af
	  section.data(1).logicalSrcIdx = 427;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.Memory1_InitialCondition_k
	  section.data(2).logicalSrcIdx = 428;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.Memory2_InitialCondition_g
	  section.data(3).logicalSrcIdx = 429;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.Memory6_InitialCondition
	  section.data(4).logicalSrcIdx = 430;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.mario_Y0
	  section.data(5).logicalSrcIdx = 431;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.Memory4_InitialCondition_g
	  section.data(6).logicalSrcIdx = 432;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_P.Delay_InitialCondition
	  section.data(7).logicalSrcIdx = 433;
	  section.data(7).dtTransOffset = 305;
	
	  ;% load_arduino_v_15_P.Constant1_Value_a
	  section.data(8).logicalSrcIdx = 434;
	  section.data(8).dtTransOffset = 306;
	
	  ;% load_arduino_v_15_P.SIUAVuint8_Value
	  section.data(9).logicalSrcIdx = 435;
	  section.data(9).dtTransOffset = 307;
	
	  ;% load_arduino_v_15_P.Memory5_InitialCondition_d
	  section.data(10).logicalSrcIdx = 436;
	  section.data(10).dtTransOffset = 308;
	
	  ;% load_arduino_v_15_P.Memory1_InitialCondition_b
	  section.data(11).logicalSrcIdx = 437;
	  section.data(11).dtTransOffset = 309;
	
	  ;% load_arduino_v_15_P.Memory_InitialCondition_o
	  section.data(12).logicalSrcIdx = 438;
	  section.data(12).dtTransOffset = 310;
	
	  ;% load_arduino_v_15_P.Memory3_InitialCondition_c
	  section.data(13).logicalSrcIdx = 439;
	  section.data(13).dtTransOffset = 311;
	
	  ;% load_arduino_v_15_P.Memory2_InitialCondition_go
	  section.data(14).logicalSrcIdx = 440;
	  section.data(14).dtTransOffset = 312;
	
	  ;% load_arduino_v_15_P.Typefixed_wingAutopilotgeneric_
	  section.data(15).logicalSrcIdx = 441;
	  section.data(15).dtTransOffset = 321;
	
	  ;% load_arduino_v_15_P.InizioMSG_Value
	  section.data(16).logicalSrcIdx = 442;
	  section.data(16).dtTransOffset = 323;
	
	  ;% load_arduino_v_15_P.FineMSG1_Value
	  section.data(17).logicalSrcIdx = 443;
	  section.data(17).dtTransOffset = 325;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.One_time_initialization.BitwiseOperator1_BitMask
	  section.data(1).logicalSrcIdx = 444;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.One_time_initialization.I2CRead12_SampleTime
	  section.data(1).logicalSrcIdx = 445;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.One_time_initialization.dig_T2_Y0
	  section.data(1).logicalSrcIdx = 446;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_T3_Y0
	  section.data(2).logicalSrcIdx = 447;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p2_Y0
	  section.data(3).logicalSrcIdx = 448;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p3_Y0
	  section.data(4).logicalSrcIdx = 449;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p4_Y0
	  section.data(5).logicalSrcIdx = 450;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p5_Y0
	  section.data(6).logicalSrcIdx = 451;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p6_Y0
	  section.data(7).logicalSrcIdx = 452;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p7_Y0
	  section.data(8).logicalSrcIdx = 453;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p8_Y0
	  section.data(9).logicalSrcIdx = 454;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p9_Y0
	  section.data(10).logicalSrcIdx = 455;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.One_time_initialization.dig_T1_Y0
	  section.data(1).logicalSrcIdx = 456;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.One_time_initialization.dig_p1_Y0
	  section.data(2).logicalSrcIdx = 457;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_P.One_time_initialization.pwm_max_min_Y0
	  section.data(3).logicalSrcIdx = 458;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_P.One_time_initialization.registromemoria2_Value
	  section.data(4).logicalSrcIdx = 459;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.One_time_initialization.Constant1_Value
	  section.data(1).logicalSrcIdx = 460;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_P.One_time_initialization.Constant4_Value
	  section.data(2).logicalSrcIdx = 461;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.ResettableSubsystem_o.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 462;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_P.ResettableSubsystem.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 463;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 19;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (load_arduino_v_15_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.Gain1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.WP_param
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.Val_out_MAV
	  section.data(2).logicalSrcIdx = 111;
	  section.data(2).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.Gain4
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.DataTypeConversion5
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 79;
      section.data(79)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.Constant2
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.Go_Home
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.RateLimiter1
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.Abs
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_B.ComplextoRealImag
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_B.Switch
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_B.V_goHome
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_B.h_goHome
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_B.RC_goHome
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_B.rotta_goHome
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_B.VELOCITA
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_B.RC
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_B.QUOTA
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_B.ROTTA
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_B.Px
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_B.Abs1
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_B.Memory5
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_B.Memory1
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_B.Memory2
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_B.velocita
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_B.SwitchdiselezioneTaskWaypointna
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_B.QUOTA_n
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_B.Switch1
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_B.In
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_B.Gain
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_B.Constant1
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 34;
	
	  ;% load_arduino_v_15_B.Sum2
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_B.Gain2
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 36;
	
	  ;% load_arduino_v_15_B.maneuver_selector
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 37;
	
	  ;% load_arduino_v_15_B.landing_selector
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 38;
	
	  ;% load_arduino_v_15_B.trig_approach
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 39;
	
	  ;% load_arduino_v_15_B.trig_flare
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 40;
	
	  ;% load_arduino_v_15_B.approach_selector
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 41;
	
	  ;% load_arduino_v_15_B.Multiply
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 42;
	
	  ;% load_arduino_v_15_B.Multiply1
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 43;
	
	  ;% load_arduino_v_15_B.Constant1_l
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 44;
	
	  ;% load_arduino_v_15_B.x_f_out
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 45;
	
	  ;% load_arduino_v_15_B.h_f_out
	  section.data(38).logicalSrcIdx = 40;
	  section.data(38).dtTransOffset = 46;
	
	  ;% load_arduino_v_15_B.k_x_out
	  section.data(39).logicalSrcIdx = 41;
	  section.data(39).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_B.h_c_out
	  section.data(40).logicalSrcIdx = 42;
	  section.data(40).dtTransOffset = 48;
	
	  ;% load_arduino_v_15_B.no_solution
	  section.data(41).logicalSrcIdx = 43;
	  section.data(41).dtTransOffset = 49;
	
	  ;% load_arduino_v_15_B.counter_out
	  section.data(42).logicalSrcIdx = 44;
	  section.data(42).dtTransOffset = 50;
	
	  ;% load_arduino_v_15_B.V_vett
	  section.data(43).logicalSrcIdx = 45;
	  section.data(43).dtTransOffset = 51;
	
	  ;% load_arduino_v_15_B.h_vett
	  section.data(44).logicalSrcIdx = 46;
	  section.data(44).dtTransOffset = 52;
	
	  ;% load_arduino_v_15_B.rotta_vett
	  section.data(45).logicalSrcIdx = 47;
	  section.data(45).dtTransOffset = 53;
	
	  ;% load_arduino_v_15_B.RC_vett
	  section.data(46).logicalSrcIdx = 48;
	  section.data(46).dtTransOffset = 54;
	
	  ;% load_arduino_v_15_B.Lat_Home
	  section.data(47).logicalSrcIdx = 49;
	  section.data(47).dtTransOffset = 55;
	
	  ;% load_arduino_v_15_B.Long_Home
	  section.data(48).logicalSrcIdx = 50;
	  section.data(48).dtTransOffset = 56;
	
	  ;% load_arduino_v_15_B.h_Home
	  section.data(49).logicalSrcIdx = 51;
	  section.data(49).dtTransOffset = 57;
	
	  ;% load_arduino_v_15_B.Constant
	  section.data(50).logicalSrcIdx = 52;
	  section.data(50).dtTransOffset = 58;
	
	  ;% load_arduino_v_15_B.Constant1_f
	  section.data(51).logicalSrcIdx = 53;
	  section.data(51).dtTransOffset = 59;
	
	  ;% load_arduino_v_15_B.Constant2_f
	  section.data(52).logicalSrcIdx = 54;
	  section.data(52).dtTransOffset = 60;
	
	  ;% load_arduino_v_15_B.Gain_f
	  section.data(53).logicalSrcIdx = 55;
	  section.data(53).dtTransOffset = 61;
	
	  ;% load_arduino_v_15_B.In_j
	  section.data(54).logicalSrcIdx = 56;
	  section.data(54).dtTransOffset = 62;
	
	  ;% load_arduino_v_15_B.In_o
	  section.data(55).logicalSrcIdx = 57;
	  section.data(55).dtTransOffset = 63;
	
	  ;% load_arduino_v_15_B.Fase_ATO
	  section.data(56).logicalSrcIdx = 58;
	  section.data(56).dtTransOffset = 64;
	
	  ;% load_arduino_v_15_B.manetta_ref
	  section.data(57).logicalSrcIdx = 59;
	  section.data(57).dtTransOffset = 65;
	
	  ;% load_arduino_v_15_B.psi_ref
	  section.data(58).logicalSrcIdx = 60;
	  section.data(58).dtTransOffset = 66;
	
	  ;% load_arduino_v_15_B.eq_rot
	  section.data(59).logicalSrcIdx = 61;
	  section.data(59).dtTransOffset = 67;
	
	  ;% load_arduino_v_15_B.pitch_ref
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 68;
	
	  ;% load_arduino_v_15_B.h_ref
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 69;
	
	  ;% load_arduino_v_15_B.Tas_ref
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 70;
	
	  ;% load_arduino_v_15_B.RC_ref
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 71;
	
	  ;% load_arduino_v_15_B.psi_ref_selector
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 72;
	
	  ;% load_arduino_v_15_B.theta_ground_selector
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 73;
	
	  ;% load_arduino_v_15_B.Switch_n
	  section.data(66).logicalSrcIdx = 74;
	  section.data(66).dtTransOffset = 74;
	
	  ;% load_arduino_v_15_B.Switch_l
	  section.data(67).logicalSrcIdx = 75;
	  section.data(67).dtTransOffset = 75;
	
	  ;% load_arduino_v_15_B.Switch_a
	  section.data(68).logicalSrcIdx = 76;
	  section.data(68).dtTransOffset = 76;
	
	  ;% load_arduino_v_15_B.switch_manetta
	  section.data(69).logicalSrcIdx = 77;
	  section.data(69).dtTransOffset = 77;
	
	  ;% load_arduino_v_15_B.switch_equilibratore
	  section.data(70).logicalSrcIdx = 78;
	  section.data(70).dtTransOffset = 78;
	
	  ;% load_arduino_v_15_B.switch_alettoni
	  section.data(71).logicalSrcIdx = 79;
	  section.data(71).dtTransOffset = 79;
	
	  ;% load_arduino_v_15_B.switch_timone
	  section.data(72).logicalSrcIdx = 80;
	  section.data(72).dtTransOffset = 80;
	
	  ;% load_arduino_v_15_B.phi_safe
	  section.data(73).logicalSrcIdx = 81;
	  section.data(73).dtTransOffset = 81;
	
	  ;% load_arduino_v_15_B.theta_safe
	  section.data(74).logicalSrcIdx = 82;
	  section.data(74).dtTransOffset = 82;
	
	  ;% load_arduino_v_15_B.throttle_safe
	  section.data(75).logicalSrcIdx = 83;
	  section.data(75).dtTransOffset = 83;
	
	  ;% load_arduino_v_15_B.modo
	  section.data(76).logicalSrcIdx = 84;
	  section.data(76).dtTransOffset = 84;
	
	  ;% load_arduino_v_15_B.OutportBufferForOut1
	  section.data(77).logicalSrcIdx = 85;
	  section.data(77).dtTransOffset = 85;
	
	  ;% load_arduino_v_15_B.mod
	  section.data(78).logicalSrcIdx = 86;
	  section.data(78).dtTransOffset = 86;
	
	  ;% load_arduino_v_15_B.test
	  section.data(79).logicalSrcIdx = 88;
	  section.data(79).dtTransOffset = 87;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.SFunctionBuilder_o2
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.Add
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.DataTypeConversion_a
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.DataTypeConversion1_i
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_B.DataTypeConversion_ay
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_B.SFunctionBuilder_o2_a
	  section.data(6).logicalSrcIdx = 117;
	  section.data(6).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.Memory
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.TmpSignalConversionAtSFunctionI
	  section.data(2).logicalSrcIdx = 122;
	  section.data(2).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_B.Heading
	  section.data(3).logicalSrcIdx = 125;
	  section.data(3).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.DataTypeConversion1_p
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.SFunction_o2
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.DataTypeConversion3
	  section.data(2).logicalSrcIdx = 90;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 91;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.DataTypeConversion8
	  section.data(4).logicalSrcIdx = 92;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_B.SFunctionBuilder1
	  section.data(5).logicalSrcIdx = 93;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.ByteUnpack_o2
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.ByteReversal
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_B.SFunction_o8
	  section.data(3).logicalSrcIdx = 96;
	  section.data(3).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_B.SFunction_o10
	  section.data(4).logicalSrcIdx = 97;
	  section.data(4).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_B.SFunction_o13
	  section.data(5).logicalSrcIdx = 98;
	  section.data(5).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_B.SFunction_o17
	  section.data(6).logicalSrcIdx = 99;
	  section.data(6).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_B.Switch1_g
	  section.data(7).logicalSrcIdx = 100;
	  section.data(7).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_B.DataTypeConversion1
	  section.data(8).logicalSrcIdx = 101;
	  section.data(8).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_B.AGAC
	  section.data(9).logicalSrcIdx = 102;
	  section.data(9).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_B.DataTypeConversion2
	  section.data(10).logicalSrcIdx = 103;
	  section.data(10).dtTransOffset = 39;
	
	  ;% load_arduino_v_15_B.DataTypeConversion_l
	  section.data(11).logicalSrcIdx = 104;
	  section.data(11).dtTransOffset = 40;
	
	  ;% load_arduino_v_15_B.DataTypeConversion1_g
	  section.data(12).logicalSrcIdx = 105;
	  section.data(12).dtTransOffset = 41;
	
	  ;% load_arduino_v_15_B.DataTypeConversion4
	  section.data(13).logicalSrcIdx = 106;
	  section.data(13).dtTransOffset = 42;
	
	  ;% load_arduino_v_15_B.T
	  section.data(14).logicalSrcIdx = 107;
	  section.data(14).dtTransOffset = 46;
	
	  ;% load_arduino_v_15_B.SFunctionBuilder_o1
	  section.data(15).logicalSrcIdx = 108;
	  section.data(15).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o2_e
	  section.data(16).logicalSrcIdx = 109;
	  section.data(16).dtTransOffset = 48;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.SFunction_o7
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.SFunction_o9
	  section.data(2).logicalSrcIdx = 120;
	  section.data(2).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.SFunction_o11
	  section.data(3).logicalSrcIdx = 121;
	  section.data(3).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.DataTypeConversion2_h
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.Throttle
	  section.data(2).logicalSrcIdx = 124;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.Memory_a
	  section.data(3).logicalSrcIdx = 126;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.SFunction_o3
	  section.data(4).logicalSrcIdx = 127;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_B.SFunction_o4
	  section.data(5).logicalSrcIdx = 128;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_B.DataTypeConversion1_h
	  section.data(6).logicalSrcIdx = 129;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o4
	  section.data(7).logicalSrcIdx = 130;
	  section.data(7).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_B.WP_info
	  section.data(8).logicalSrcIdx = 131;
	  section.data(8).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_B.new_mex
	  section.data(9).logicalSrcIdx = 132;
	  section.data(9).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_B.GC_info
	  section.data(10).logicalSrcIdx = 133;
	  section.data(10).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.SFunctionBuilder2
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.PWM_aileron
	  section.data(2).logicalSrcIdx = 135;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.DataTypeConversion1_c
	  section.data(3).logicalSrcIdx = 136;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.PWM_throttle
	  section.data(4).logicalSrcIdx = 137;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_B.Sum
	  section.data(5).logicalSrcIdx = 138;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_B.PWM_rudder
	  section.data(6).logicalSrcIdx = 139;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_B.DataTypeConversion2_j
	  section.data(7).logicalSrcIdx = 140;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_B.PWM_elevator
	  section.data(8).logicalSrcIdx = 141;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_B.DataTypeConversion_p
	  section.data(9).logicalSrcIdx = 142;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_B.Gain1_p
	  section.data(10).logicalSrcIdx = 143;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_B.DataTypeConversion_ld
	  section.data(11).logicalSrcIdx = 144;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_B.Heading_g
	  section.data(12).logicalSrcIdx = 146;
	  section.data(12).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_B.DataTypeConversion2_m
	  section.data(13).logicalSrcIdx = 147;
	  section.data(13).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_B.DataTypeConversion_lx
	  section.data(14).logicalSrcIdx = 148;
	  section.data(14).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o3
	  section.data(15).logicalSrcIdx = 149;
	  section.data(15).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.SFunctionBuilder_o1_n
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.SFunctionBuilder_o1_h
	  section.data(2).logicalSrcIdx = 154;
	  section.data(2).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.SFunctionBuilder_o2_f
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o1
	  section.data(2).logicalSrcIdx = 152;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o3_p
	  section.data(3).logicalSrcIdx = 153;
	  section.data(3).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_B.Memory1_p
	  section.data(4).logicalSrcIdx = 155;
	  section.data(4).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_B.Memory_k
	  section.data(5).logicalSrcIdx = 156;
	  section.data(5).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_B.Memory3
	  section.data(6).logicalSrcIdx = 157;
	  section.data(6).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_B.SFunction_o1
	  section.data(7).logicalSrcIdx = 158;
	  section.data(7).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_B.SFunction_o3_j
	  section.data(8).logicalSrcIdx = 159;
	  section.data(8).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_B.SFunction_o4_n
	  section.data(9).logicalSrcIdx = 160;
	  section.data(9).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_B.SFunction_o5
	  section.data(10).logicalSrcIdx = 161;
	  section.data(10).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_B.SFunction_o6
	  section.data(11).logicalSrcIdx = 162;
	  section.data(11).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_B.SFunction_o12
	  section.data(12).logicalSrcIdx = 163;
	  section.data(12).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_B.SFunction_o14
	  section.data(13).logicalSrcIdx = 164;
	  section.data(13).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_B.SFunction_o15
	  section.data(14).logicalSrcIdx = 165;
	  section.data(14).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_B.SFunction_o16
	  section.data(15).logicalSrcIdx = 166;
	  section.data(15).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_B.TmpSignalConversionAtSFunctio_m
	  section.data(16).logicalSrcIdx = 167;
	  section.data(16).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_B.SFunction_o1_j
	  section.data(17).logicalSrcIdx = 168;
	  section.data(17).dtTransOffset = 32;
	
	  ;% load_arduino_v_15_B.SFunction_o2_f
	  section.data(18).logicalSrcIdx = 169;
	  section.data(18).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_B.TmpSignalConversionAtBytePackIn
	  section.data(19).logicalSrcIdx = 170;
	  section.data(19).dtTransOffset = 297;
	
	  ;% load_arduino_v_15_B.BytePack
	  section.data(20).logicalSrcIdx = 171;
	  section.data(20).dtTransOffset = 299;
	
	  ;% load_arduino_v_15_B.Mex_out
	  section.data(21).logicalSrcIdx = 172;
	  section.data(21).dtTransOffset = 362;
	
	  ;% load_arduino_v_15_B.indice_dimario
	  section.data(22).logicalSrcIdx = 173;
	  section.data(22).dtTransOffset = 403;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o1_o
	  section.data(23).logicalSrcIdx = 174;
	  section.data(23).dtTransOffset = 404;
	
	  ;% load_arduino_v_15_B.ByteUnpack_o5
	  section.data(24).logicalSrcIdx = 175;
	  section.data(24).dtTransOffset = 406;
	
	  ;% load_arduino_v_15_B.messaggio
	  section.data(25).logicalSrcIdx = 176;
	  section.data(25).dtTransOffset = 407;
	
	  ;% load_arduino_v_15_B.iflogic
	  section.data(26).logicalSrcIdx = 177;
	  section.data(26).dtTransOffset = 438;
	
	  ;% load_arduino_v_15_B.mess_out
	  section.data(27).logicalSrcIdx = 179;
	  section.data(27).dtTransOffset = 439;
	
	  ;% load_arduino_v_15_B.AP_int
	  section.data(28).logicalSrcIdx = 180;
	  section.data(28).dtTransOffset = 539;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.B_Remaining
	  section.data(1).logicalSrcIdx = 181;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.Ap_sel
	  section.data(1).logicalSrcIdx = 182;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.HitCrossing
	  section.data(2).logicalSrcIdx = 183;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.One_time_initialization.ByteUnpack
	  section.data(1).logicalSrcIdx = 184;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead3
	  section.data(2).logicalSrcIdx = 185;
	  section.data(2).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead
	  section.data(3).logicalSrcIdx = 186;
	  section.data(3).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead9
	  section.data(1).logicalSrcIdx = 187;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead8
	  section.data(2).logicalSrcIdx = 188;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead7
	  section.data(3).logicalSrcIdx = 189;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead6
	  section.data(4).logicalSrcIdx = 190;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead5
	  section.data(5).logicalSrcIdx = 191;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead4
	  section.data(6).logicalSrcIdx = 192;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead2
	  section.data(7).logicalSrcIdx = 193;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead11
	  section.data(8).logicalSrcIdx = 194;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead10
	  section.data(9).logicalSrcIdx = 195;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead1
	  section.data(10).logicalSrcIdx = 196;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_B.One_time_initialization.I2CRead12
	  section.data(1).logicalSrcIdx = 197;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 20;
    sectIdxOffset = 19;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (load_arduino_v_15_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.obj_o
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.obj_e
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.obj_m
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.obj_f
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.obj_p
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.obj_b
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.obj_d
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 56;
      section.data(56)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.SFunctionBuilder_DSTATE
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.SFunctionBuilder_DSTATE_l
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_DW.Filter_DSTATE
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_d
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_DW.SFunctionBuilder10_DSTATE
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_n
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_DW.SFunctionBuilder4_DSTATE
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_DW.DiscreteWashoutFilter_states
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_DW.SFunctionBuilder5_DSTATE
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_h
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_g
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_DW.Filter_DSTATE_l
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_d5
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_DW.Filter_DSTATE_k
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_l
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_DW.SFunctionBuilder9_DSTATE
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_DW.DelayInput2_DSTATE
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_DW.SFunctionBuilder_DSTATE_n
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_DW.Filter_DSTATE_g
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_DW.Integrator_DSTATE_o
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_DW.DiscreteTimeIntegrator_DSTATE_m
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_DW.PrevY
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_DW.PrevY_o
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_DW.RateTransition_Buffer0
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_DW.Memory1_PreviousInput
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_DW.Memory2_PreviousInput
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_l
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_DW.P_ref
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 38;
	
	  ;% load_arduino_v_15_DW.rl_up
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 39;
	
	  ;% load_arduino_v_15_DW.rl_dw
	  section.data(33).logicalSrcIdx = 41;
	  section.data(33).dtTransOffset = 40;
	
	  ;% load_arduino_v_15_DW.flag
	  section.data(34).logicalSrcIdx = 42;
	  section.data(34).dtTransOffset = 41;
	
	  ;% load_arduino_v_15_DW.Memory4_PreviousInput
	  section.data(35).logicalSrcIdx = 43;
	  section.data(35).dtTransOffset = 42;
	
	  ;% load_arduino_v_15_DW.flag_l
	  section.data(36).logicalSrcIdx = 44;
	  section.data(36).dtTransOffset = 43;
	
	  ;% load_arduino_v_15_DW.lat1
	  section.data(37).logicalSrcIdx = 45;
	  section.data(37).dtTransOffset = 44;
	
	  ;% load_arduino_v_15_DW.long1
	  section.data(38).logicalSrcIdx = 46;
	  section.data(38).dtTransOffset = 45;
	
	  ;% load_arduino_v_15_DW.Memory7_PreviousInput
	  section.data(39).logicalSrcIdx = 47;
	  section.data(39).dtTransOffset = 46;
	
	  ;% load_arduino_v_15_DW.Memory5_PreviousInput
	  section.data(40).logicalSrcIdx = 48;
	  section.data(40).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_DW.Memory1_PreviousInput_i
	  section.data(41).logicalSrcIdx = 49;
	  section.data(41).dtTransOffset = 48;
	
	  ;% load_arduino_v_15_DW.Memory2_PreviousInput_o
	  section.data(42).logicalSrcIdx = 50;
	  section.data(42).dtTransOffset = 49;
	
	  ;% load_arduino_v_15_DW.x
	  section.data(43).logicalSrcIdx = 51;
	  section.data(43).dtTransOffset = 50;
	
	  ;% load_arduino_v_15_DW.cycle_count
	  section.data(44).logicalSrcIdx = 52;
	  section.data(44).dtTransOffset = 54;
	
	  ;% load_arduino_v_15_DW.eps
	  section.data(45).logicalSrcIdx = 53;
	  section.data(45).dtTransOffset = 55;
	
	  ;% load_arduino_v_15_DW.flag_m
	  section.data(46).logicalSrcIdx = 54;
	  section.data(46).dtTransOffset = 59;
	
	  ;% load_arduino_v_15_DW.Memory3_PreviousInput
	  section.data(47).logicalSrcIdx = 55;
	  section.data(47).dtTransOffset = 60;
	
	  ;% load_arduino_v_15_DW.V_ref
	  section.data(48).logicalSrcIdx = 56;
	  section.data(48).dtTransOffset = 61;
	
	  ;% load_arduino_v_15_DW.ALT_ref
	  section.data(49).logicalSrcIdx = 57;
	  section.data(49).dtTransOffset = 62;
	
	  ;% load_arduino_v_15_DW.HDG_ref
	  section.data(50).logicalSrcIdx = 58;
	  section.data(50).dtTransOffset = 63;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_a
	  section.data(51).logicalSrcIdx = 59;
	  section.data(51).dtTransOffset = 64;
	
	  ;% load_arduino_v_15_DW.Memory1_PreviousInput_m
	  section.data(52).logicalSrcIdx = 60;
	  section.data(52).dtTransOffset = 65;
	
	  ;% load_arduino_v_15_DW.alarm
	  section.data(53).logicalSrcIdx = 61;
	  section.data(53).dtTransOffset = 66;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_h
	  section.data(54).logicalSrcIdx = 62;
	  section.data(54).dtTransOffset = 67;
	
	  ;% load_arduino_v_15_DW.mess_len
	  section.data(55).logicalSrcIdx = 64;
	  section.data(55).dtTransOffset = 68;
	
	  ;% load_arduino_v_15_DW.test1
	  section.data(56).logicalSrcIdx = 65;
	  section.data(56).dtTransOffset = 69;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.riferimenti
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.WP_dbP
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_DW.WP_dbP_AL
	  section.data(3).logicalSrcIdx = 68;
	  section.data(3).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.clockTickCounter_c
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.is_c17_load_arduino_v_15
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.is_c2_load_arduino_v_15
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_DW.is_c1_load_arduino_v_15
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_DW.is_c26_load_arduino_v_15
	  section.data(4).logicalSrcIdx = 80;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_DW.is_AUTOMATICA
	  section.data(5).logicalSrcIdx = 81;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_DW.is_c23_load_arduino_v_15
	  section.data(6).logicalSrcIdx = 82;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_DW.is_c9_load_arduino_v_15
	  section.data(7).logicalSrcIdx = 83;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.HitCrossing_MODE
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_i
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_n
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_DW.counter
	  section.data(3).logicalSrcIdx = 87;
	  section.data(3).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_DW.WP_dbI
	  section.data(4).logicalSrcIdx = 88;
	  section.data(4).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.Integrator_PrevResetState
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_DW.Integrator_PrevResetState_c
	  section.data(3).logicalSrcIdx = 93;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_DW.Integrator_PrevResetState_a
	  section.data(4).logicalSrcIdx = 94;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_DW.Filter_PrevResetState
	  section.data(5).logicalSrcIdx = 95;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_DW.Integrator_PrevResetState_f
	  section.data(6).logicalSrcIdx = 96;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_DW.Filter_PrevResetState_f
	  section.data(7).logicalSrcIdx = 97;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_DW.Subsystem2_SubsysRanBC
	  section.data(8).logicalSrcIdx = 98;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_DW.Subsystem_SubsysRanBC
	  section.data(9).logicalSrcIdx = 99;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_DW.Subsystem1_SubsysRanBC
	  section.data(10).logicalSrcIdx = 100;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_DW.Subsystem1_SubsysRanBC_n
	  section.data(11).logicalSrcIdx = 101;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_DW.Execution_loop_SubsysRanBC
	  section.data(12).logicalSrcIdx = 102;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_DW.Subsystem1_SubsysRanBC_l
	  section.data(13).logicalSrcIdx = 103;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_DW.Subsystem2_SubsysRanBC_m
	  section.data(14).logicalSrcIdx = 104;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_DW.Subsystem3_SubsysRanBC
	  section.data(15).logicalSrcIdx = 105;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_DW.Subsystem2_SubsysRanBC_d
	  section.data(16).logicalSrcIdx = 106;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_DW.Subsystem1_SubsysRanBC_nk
	  section.data(17).logicalSrcIdx = 107;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_DW.SampleandHold_SubsysRanBC
	  section.data(18).logicalSrcIdx = 108;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_DW.INSEGUIMENTOCENTROPISTA_SubsysR
	  section.data(19).logicalSrcIdx = 109;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_DW.FLARE_SubsysRanBC
	  section.data(20).logicalSrcIdx = 110;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_DW.APPROACH_SubsysRanBC
	  section.data(21).logicalSrcIdx = 111;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_DW.DiscreteTimeIntegrator_PrevRe_h
	  section.data(22).logicalSrcIdx = 112;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_DW.Subsystem_SubsysRanBC_f
	  section.data(23).logicalSrcIdx = 113;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_DW.DECOLLOAUTOMATICO_SubsysRanBC
	  section.data(24).logicalSrcIdx = 114;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_DW.SampleandHold1_SubsysRanBC
	  section.data(25).logicalSrcIdx = 115;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_DW.SampleandHold_SubsysRanBC_i
	  section.data(26).logicalSrcIdx = 116;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_DW.Enabled_SubsysRanBC
	  section.data(27).logicalSrcIdx = 117;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_DW.Enabled_SubsysRanBC_p
	  section.data(28).logicalSrcIdx = 118;
	  section.data(28).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_DW.Enabled_SubsysRanBC_o
	  section.data(29).logicalSrcIdx = 119;
	  section.data(29).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_DW.EnabledSubsystem_SubsysRanBC
	  section.data(30).logicalSrcIdx = 120;
	  section.data(30).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_DW.EnabledSubsystem_SubsysRanBC_c
	  section.data(31).logicalSrcIdx = 121;
	  section.data(31).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_DW.EnabledSubsystem_SubsysRanBC_n
	  section.data(32).logicalSrcIdx = 122;
	  section.data(32).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_DW.Enable_SubsysRanBC
	  section.data(33).logicalSrcIdx = 123;
	  section.data(33).dtTransOffset = 32;
	
	  ;% load_arduino_v_15_DW.sendbyte_SubsysRanBC
	  section.data(34).logicalSrcIdx = 124;
	  section.data(34).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.Memory4_PreviousInput_c
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.Memory5_PreviousInput_l
	  section.data(2).logicalSrcIdx = 126;
	  section.data(2).dtTransOffset = 300;
	
	  ;% load_arduino_v_15_DW.Memory1_PreviousInput_d
	  section.data(3).logicalSrcIdx = 127;
	  section.data(3).dtTransOffset = 400;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_h5
	  section.data(4).logicalSrcIdx = 128;
	  section.data(4).dtTransOffset = 402;
	
	  ;% load_arduino_v_15_DW.Memory3_PreviousInput_o
	  section.data(5).logicalSrcIdx = 129;
	  section.data(5).dtTransOffset = 406;
	
	  ;% load_arduino_v_15_DW.Memory2_PreviousInput_a
	  section.data(6).logicalSrcIdx = 130;
	  section.data(6).dtTransOffset = 407;
	
	  ;% load_arduino_v_15_DW.message
	  section.data(7).logicalSrcIdx = 131;
	  section.data(7).dtTransOffset = 416;
	
	  ;% load_arduino_v_15_DW.counter_k
	  section.data(8).logicalSrcIdx = 132;
	  section.data(8).dtTransOffset = 496;
	
	  ;% load_arduino_v_15_DW.message_k
	  section.data(9).logicalSrcIdx = 133;
	  section.data(9).dtTransOffset = 497;
	
	  ;% load_arduino_v_15_DW.counter_n
	  section.data(10).logicalSrcIdx = 134;
	  section.data(10).dtTransOffset = 528;
	
	  ;% load_arduino_v_15_DW.is_active_c17_load_arduino_v_15
	  section.data(11).logicalSrcIdx = 135;
	  section.data(11).dtTransOffset = 529;
	
	  ;% load_arduino_v_15_DW.Memory_PreviousInput_b
	  section.data(12).logicalSrcIdx = 136;
	  section.data(12).dtTransOffset = 530;
	
	  ;% load_arduino_v_15_DW.Memory1_PreviousInput_a
	  section.data(13).logicalSrcIdx = 137;
	  section.data(13).dtTransOffset = 531;
	
	  ;% load_arduino_v_15_DW.Memory2_PreviousInput_d
	  section.data(14).logicalSrcIdx = 138;
	  section.data(14).dtTransOffset = 532;
	
	  ;% load_arduino_v_15_DW.Memory6_PreviousInput
	  section.data(15).logicalSrcIdx = 139;
	  section.data(15).dtTransOffset = 533;
	
	  ;% load_arduino_v_15_DW.is_active_c2_load_arduino_v_15
	  section.data(16).logicalSrcIdx = 140;
	  section.data(16).dtTransOffset = 534;
	
	  ;% load_arduino_v_15_DW.temporalCounter_i1
	  section.data(17).logicalSrcIdx = 141;
	  section.data(17).dtTransOffset = 535;
	
	  ;% load_arduino_v_15_DW.is_active_c1_load_arduino_v_15
	  section.data(18).logicalSrcIdx = 142;
	  section.data(18).dtTransOffset = 536;
	
	  ;% load_arduino_v_15_DW.is_active_c26_load_arduino_v_15
	  section.data(19).logicalSrcIdx = 143;
	  section.data(19).dtTransOffset = 537;
	
	  ;% load_arduino_v_15_DW.is_active_c23_load_arduino_v_15
	  section.data(20).logicalSrcIdx = 144;
	  section.data(20).dtTransOffset = 538;
	
	  ;% load_arduino_v_15_DW.is_active_c9_load_arduino_v_15
	  section.data(21).logicalSrcIdx = 145;
	  section.data(21).dtTransOffset = 539;
	
	  ;% load_arduino_v_15_DW.i
	  section.data(22).logicalSrcIdx = 146;
	  section.data(22).dtTransOffset = 540;
	
	  ;% load_arduino_v_15_DW.message_i
	  section.data(23).logicalSrcIdx = 147;
	  section.data(23).dtTransOffset = 541;
	
	  ;% load_arduino_v_15_DW.counter_a
	  section.data(24).logicalSrcIdx = 148;
	  section.data(24).dtTransOffset = 641;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.start_found
	  section.data(1).logicalSrcIdx = 149;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.end_found
	  section.data(2).logicalSrcIdx = 150;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_DW.start_found_c
	  section.data(3).logicalSrcIdx = 154;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_DW.x_not_empty
	  section.data(4).logicalSrcIdx = 159;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_DW.x_new_not_empty
	  section.data(5).logicalSrcIdx = 160;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_DW.cycle_count_not_empty
	  section.data(6).logicalSrcIdx = 161;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_DW.eps_not_empty
	  section.data(7).logicalSrcIdx = 162;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_DW.Tf_not_empty
	  section.data(8).logicalSrcIdx = 163;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_DW.Interr_parz
	  section.data(9).logicalSrcIdx = 165;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_DW.WP_dbP_not_empty
	  section.data(10).logicalSrcIdx = 166;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_DW.WP_dbP_AL_not_empty
	  section.data(11).logicalSrcIdx = 167;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_DW.Enabled_MODE
	  section.data(12).logicalSrcIdx = 168;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_DW.Enabled_MODE_g
	  section.data(13).logicalSrcIdx = 169;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_DW.Enabled_MODE_m
	  section.data(14).logicalSrcIdx = 170;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.One_time_initialization.obj
	  section.data(1).logicalSrcIdx = 171;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_i
	  section.data(2).logicalSrcIdx = 172;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_c
	  section.data(3).logicalSrcIdx = 173;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_b
	  section.data(4).logicalSrcIdx = 174;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_k
	  section.data(5).logicalSrcIdx = 175;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_co
	  section.data(6).logicalSrcIdx = 176;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_k4
	  section.data(7).logicalSrcIdx = 177;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_d
	  section.data(8).logicalSrcIdx = 178;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_ir
	  section.data(9).logicalSrcIdx = 179;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_l
	  section.data(10).logicalSrcIdx = 180;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_d0
	  section.data(11).logicalSrcIdx = 181;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_o
	  section.data(12).logicalSrcIdx = 182;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_kf
	  section.data(13).logicalSrcIdx = 183;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_d01
	  section.data(1).logicalSrcIdx = 184;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_in
	  section.data(2).logicalSrcIdx = 185;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_DW.One_time_initialization.obj_j
	  section.data(3).logicalSrcIdx = 186;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.One_time_initialization.One_time_initialization_SubsysR
	  section.data(1).logicalSrcIdx = 187;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.ResettableSubsystem_o.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 204;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_DW.ResettableSubsystem.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 205;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2635457160;
  targMap.checksum1 = 3588884537;
  targMap.checksum2 = 2864135395;
  targMap.checksum3 = 3652443430;

