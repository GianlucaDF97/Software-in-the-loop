  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (PROVA_FINALE_LOAD_ARDUINO_15__P)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Kp_comp_h
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Amax
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Amin
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Emax
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Emin
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Rmax
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Rmin
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Tmax
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.attuatore_Tmin
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.interventoA_05
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.interventoA_1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.interventoE_05
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.interventoE_1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.interventoT
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.inv_A
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.inv_E
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.inv_R
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.inv_comp_h
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.phi_max
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.phi_min
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.safe_V
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.safe_phi
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.t_AP
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.theta_max
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.theta_min
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.time_alarm_SAFE
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.vel_wp1_al
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.vel_wp2_al
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Ki_becch
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Ki_roll
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Kp_becch
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Kp_imb
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Kp_p
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Kp_q
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Kp_roll
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.K_imb_inv
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 236;
      section.data(236)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PIDController_InitialConditionF
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PIDController_InitialConditio_d
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PIDController_Kb
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PIDController_Kb_k
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PIDController_Kt
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PIDController_Kt_m
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.CompareToConstant_const
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.CompareToConstant_const_d
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.CompareToConstant_const_p
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.CompareToConstant_const_b
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.CompareToConstant_const_dp
	  section.data(11).logicalSrcIdx = 46;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.CompareToConstant_const_g
	  section.data(12).logicalSrcIdx = 47;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.SerialTransmit_Protocol
	  section.data(13).logicalSrcIdx = 48;
	  section.data(13).dtTransOffset = 12;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value
	  section.data(14).logicalSrcIdx = 49;
	  section.data(14).dtTransOffset = 13;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out1_Y0
	  section.data(15).logicalSrcIdx = 50;
	  section.data(15).dtTransOffset = 14;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant5_Value
	  section.data(16).logicalSrcIdx = 51;
	  section.data(16).dtTransOffset = 15;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch1_Threshold
	  section.data(17).logicalSrcIdx = 52;
	  section.data(17).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.r_rif_Value
	  section.data(18).logicalSrcIdx = 53;
	  section.data(18).dtTransOffset = 17;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value
	  section.data(19).logicalSrcIdx = 54;
	  section.data(19).dtTransOffset = 18;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_k
	  section.data(20).logicalSrcIdx = 55;
	  section.data(20).dtTransOffset = 19;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.u0_Y0
	  section.data(21).logicalSrcIdx = 56;
	  section.data(21).dtTransOffset = 20;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch_Threshold
	  section.data(22).logicalSrcIdx = 57;
	  section.data(22).dtTransOffset = 21;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_e
	  section.data(23).logicalSrcIdx = 58;
	  section.data(23).dtTransOffset = 22;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_n
	  section.data(24).logicalSrcIdx = 59;
	  section.data(24).dtTransOffset = 23;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.u0_Y0_i
	  section.data(25).logicalSrcIdx = 60;
	  section.data(25).dtTransOffset = 24;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch_Threshold_g
	  section.data(26).logicalSrcIdx = 61;
	  section.data(26).dtTransOffset = 25;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Alarm_Int_Y0
	  section.data(27).logicalSrcIdx = 62;
	  section.data(27).dtTransOffset = 26;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Alarm_Int_Y0_j
	  section.data(28).logicalSrcIdx = 63;
	  section.data(28).dtTransOffset = 27;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value
	  section.data(29).logicalSrcIdx = 64;
	  section.data(29).dtTransOffset = 28;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_i
	  section.data(30).logicalSrcIdx = 65;
	  section.data(30).dtTransOffset = 29;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.AlarmSafe_Y0
	  section.data(31).logicalSrcIdx = 66;
	  section.data(31).dtTransOffset = 30;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition
	  section.data(32).logicalSrcIdx = 67;
	  section.data(32).dtTransOffset = 31;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_d
	  section.data(33).logicalSrcIdx = 68;
	  section.data(33).dtTransOffset = 32;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain
	  section.data(34).logicalSrcIdx = 69;
	  section.data(34).dtTransOffset = 33;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_i
	  section.data(35).logicalSrcIdx = 70;
	  section.data(35).dtTransOffset = 34;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P._Y0
	  section.data(36).logicalSrcIdx = 71;
	  section.data(36).dtTransOffset = 35;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P._Y0_a
	  section.data(37).logicalSrcIdx = 72;
	  section.data(37).dtTransOffset = 36;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_g
	  section.data(38).logicalSrcIdx = 73;
	  section.data(38).dtTransOffset = 37;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_a
	  section.data(39).logicalSrcIdx = 74;
	  section.data(39).dtTransOffset = 38;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_m
	  section.data(40).logicalSrcIdx = 75;
	  section.data(40).dtTransOffset = 39;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory1_InitialCondition
	  section.data(41).logicalSrcIdx = 76;
	  section.data(41).dtTransOffset = 40;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out1_Y0_d
	  section.data(42).logicalSrcIdx = 77;
	  section.data(42).dtTransOffset = 41;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out2_Y0
	  section.data(43).logicalSrcIdx = 78;
	  section.data(43).dtTransOffset = 42;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out3_Y0
	  section.data(44).logicalSrcIdx = 79;
	  section.data(44).dtTransOffset = 43;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out4_Y0
	  section.data(45).logicalSrcIdx = 80;
	  section.data(45).dtTransOffset = 44;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory3_InitialCondition
	  section.data(46).logicalSrcIdx = 81;
	  section.data(46).dtTransOffset = 45;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_e
	  section.data(47).logicalSrcIdx = 82;
	  section.data(47).dtTransOffset = 46;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.h_ref_Y0
	  section.data(48).logicalSrcIdx = 83;
	  section.data(48).dtTransOffset = 47;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.flare_data_Y0
	  section.data(49).logicalSrcIdx = 84;
	  section.data(49).dtTransOffset = 48;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.landing_abort_Y0
	  section.data(50).logicalSrcIdx = 85;
	  section.data(50).dtTransOffset = 49;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.rc_ref_app_Y0
	  section.data(51).logicalSrcIdx = 86;
	  section.data(51).dtTransOffset = 50;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.x_g0_Value
	  section.data(52).logicalSrcIdx = 87;
	  section.data(52).dtTransOffset = 51;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value
	  section.data(53).logicalSrcIdx = 88;
	  section.data(53).dtTransOffset = 52;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant4_Value
	  section.data(54).logicalSrcIdx = 89;
	  section.data(54).dtTransOffset = 53;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteTimeIntegrator_gainval
	  section.data(55).logicalSrcIdx = 90;
	  section.data(55).dtTransOffset = 54;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteTimeIntegrator_IC
	  section.data(56).logicalSrcIdx = 91;
	  section.data(56).dtTransOffset = 55;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteTimeIntegrator_UpperSat
	  section.data(57).logicalSrcIdx = 92;
	  section.data(57).dtTransOffset = 56;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteTimeIntegrator_LowerSat
	  section.data(58).logicalSrcIdx = 93;
	  section.data(58).dtTransOffset = 57;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch_Threshold_b
	  section.data(59).logicalSrcIdx = 94;
	  section.data(59).dtTransOffset = 58;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_e0
	  section.data(60).logicalSrcIdx = 95;
	  section.data(60).dtTransOffset = 59;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_g
	  section.data(61).logicalSrcIdx = 96;
	  section.data(61).dtTransOffset = 60;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.h_ref_Y0_n
	  section.data(62).logicalSrcIdx = 97;
	  section.data(62).dtTransOffset = 61;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.RC_ref_Y0
	  section.data(63).logicalSrcIdx = 98;
	  section.data(63).dtTransOffset = 62;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_j
	  section.data(64).logicalSrcIdx = 99;
	  section.data(64).dtTransOffset = 63;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.psi_ref_landing_Y0
	  section.data(65).logicalSrcIdx = 100;
	  section.data(65).dtTransOffset = 64;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias_Bias
	  section.data(66).logicalSrcIdx = 101;
	  section.data(66).dtTransOffset = 65;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_b
	  section.data(67).logicalSrcIdx = 102;
	  section.data(67).dtTransOffset = 66;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias1_Bias
	  section.data(68).logicalSrcIdx = 103;
	  section.data(68).dtTransOffset = 67;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_i
	  section.data(69).logicalSrcIdx = 104;
	  section.data(69).dtTransOffset = 68;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias_Bias_n
	  section.data(70).logicalSrcIdx = 105;
	  section.data(70).dtTransOffset = 69;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias1_Bias_n
	  section.data(71).logicalSrcIdx = 106;
	  section.data(71).dtTransOffset = 70;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_n
	  section.data(72).logicalSrcIdx = 107;
	  section.data(72).dtTransOffset = 71;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_p
	  section.data(73).logicalSrcIdx = 108;
	  section.data(73).dtTransOffset = 72;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_gk
	  section.data(74).logicalSrcIdx = 109;
	  section.data(74).dtTransOffset = 73;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias_Bias_j
	  section.data(75).logicalSrcIdx = 110;
	  section.data(75).dtTransOffset = 74;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias1_Bias_g
	  section.data(76).logicalSrcIdx = 111;
	  section.data(76).dtTransOffset = 75;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias_Bias_f
	  section.data(77).logicalSrcIdx = 112;
	  section.data(77).dtTransOffset = 76;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_mn
	  section.data(78).logicalSrcIdx = 113;
	  section.data(78).dtTransOffset = 77;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias1_Bias_f
	  section.data(79).logicalSrcIdx = 114;
	  section.data(79).dtTransOffset = 78;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_nv
	  section.data(80).logicalSrcIdx = 115;
	  section.data(80).dtTransOffset = 79;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias_Bias_e
	  section.data(81).logicalSrcIdx = 116;
	  section.data(81).dtTransOffset = 80;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias1_Bias_j
	  section.data(82).logicalSrcIdx = 117;
	  section.data(82).dtTransOffset = 81;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_d
	  section.data(83).logicalSrcIdx = 118;
	  section.data(83).dtTransOffset = 82;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_d5
	  section.data(84).logicalSrcIdx = 119;
	  section.data(84).dtTransOffset = 83;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_b
	  section.data(85).logicalSrcIdx = 120;
	  section.data(85).dtTransOffset = 84;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias_Bias_jc
	  section.data(86).logicalSrcIdx = 121;
	  section.data(86).dtTransOffset = 85;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Bias1_Bias_gb
	  section.data(87).logicalSrcIdx = 122;
	  section.data(87).dtTransOffset = 86;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P._Y0_b
	  section.data(88).logicalSrcIdx = 123;
	  section.data(88).dtTransOffset = 87;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_c
	  section.data(89).logicalSrcIdx = 124;
	  section.data(89).dtTransOffset = 89;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant8_Value
	  section.data(90).logicalSrcIdx = 125;
	  section.data(90).dtTransOffset = 90;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.TAS_AL_Y0
	  section.data(91).logicalSrcIdx = 126;
	  section.data(91).dtTransOffset = 91;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.QUOTA_AL_Y0
	  section.data(92).logicalSrcIdx = 127;
	  section.data(92).dtTransOffset = 92;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.RC_AL_Y0
	  section.data(93).logicalSrcIdx = 128;
	  section.data(93).dtTransOffset = 93;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.ROTTA_AL_Y0
	  section.data(94).logicalSrcIdx = 129;
	  section.data(94).dtTransOffset = 94;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.H_LAT_Y0
	  section.data(95).logicalSrcIdx = 130;
	  section.data(95).dtTransOffset = 95;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.H_LONG_Y0
	  section.data(96).logicalSrcIdx = 131;
	  section.data(96).dtTransOffset = 96;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.H_ALT_Y0
	  section.data(97).logicalSrcIdx = 132;
	  section.data(97).dtTransOffset = 97;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.distancewaypointsvirtuale_Value
	  section.data(98).logicalSrcIdx = 133;
	  section.data(98).dtTransOffset = 98;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_es
	  section.data(99).logicalSrcIdx = 134;
	  section.data(99).dtTransOffset = 101;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_k
	  section.data(100).logicalSrcIdx = 135;
	  section.data(100).dtTransOffset = 102;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.altwaypointvirtuale_Value
	  section.data(101).logicalSrcIdx = 136;
	  section.data(101).dtTransOffset = 103;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_f
	  section.data(102).logicalSrcIdx = 137;
	  section.data(102).dtTransOffset = 106;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_d
	  section.data(103).logicalSrcIdx = 138;
	  section.data(103).dtTransOffset = 107;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_p
	  section.data(104).logicalSrcIdx = 139;
	  section.data(104).dtTransOffset = 108;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_b2
	  section.data(105).logicalSrcIdx = 140;
	  section.data(105).dtTransOffset = 109;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain1_Gain
	  section.data(106).logicalSrcIdx = 141;
	  section.data(106).dtTransOffset = 110;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_j
	  section.data(107).logicalSrcIdx = 142;
	  section.data(107).dtTransOffset = 111;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_nw
	  section.data(108).logicalSrcIdx = 143;
	  section.data(108).dtTransOffset = 112;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant4_Value_o
	  section.data(109).logicalSrcIdx = 144;
	  section.data(109).dtTransOffset = 113;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_j
	  section.data(110).logicalSrcIdx = 145;
	  section.data(110).dtTransOffset = 114;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.f_Value
	  section.data(111).logicalSrcIdx = 146;
	  section.data(111).dtTransOffset = 115;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain1_Gain_j
	  section.data(112).logicalSrcIdx = 147;
	  section.data(112).dtTransOffset = 116;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_j
	  section.data(113).logicalSrcIdx = 148;
	  section.data(113).dtTransOffset = 117;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_h
	  section.data(114).logicalSrcIdx = 149;
	  section.data(114).dtTransOffset = 118;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_f
	  section.data(115).logicalSrcIdx = 150;
	  section.data(115).dtTransOffset = 119;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_o
	  section.data(116).logicalSrcIdx = 151;
	  section.data(116).dtTransOffset = 120;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_ov
	  section.data(117).logicalSrcIdx = 152;
	  section.data(117).dtTransOffset = 121;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_jp
	  section.data(118).logicalSrcIdx = 153;
	  section.data(118).dtTransOffset = 122;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory7_InitialCondition
	  section.data(119).logicalSrcIdx = 154;
	  section.data(119).dtTransOffset = 123;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory5_InitialCondition
	  section.data(120).logicalSrcIdx = 155;
	  section.data(120).dtTransOffset = 124;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory1_InitialCondition_f
	  section.data(121).logicalSrcIdx = 156;
	  section.data(121).dtTransOffset = 125;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory2_InitialCondition
	  section.data(122).logicalSrcIdx = 157;
	  section.data(122).dtTransOffset = 126;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant4_Value_j
	  section.data(123).logicalSrcIdx = 158;
	  section.data(123).dtTransOffset = 127;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_n3
	  section.data(124).logicalSrcIdx = 159;
	  section.data(124).dtTransOffset = 128;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch2_Threshold
	  section.data(125).logicalSrcIdx = 160;
	  section.data(125).dtTransOffset = 129;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.RC_Y0
	  section.data(126).logicalSrcIdx = 161;
	  section.data(126).dtTransOffset = 130;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.VELOCITA_Y0
	  section.data(127).logicalSrcIdx = 162;
	  section.data(127).dtTransOffset = 131;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out3_Y0_j
	  section.data(128).logicalSrcIdx = 163;
	  section.data(128).dtTransOffset = 132;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out4_Y0_m
	  section.data(129).logicalSrcIdx = 164;
	  section.data(129).dtTransOffset = 133;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory4_InitialCondition
	  section.data(130).logicalSrcIdx = 165;
	  section.data(130).dtTransOffset = 134;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_bu
	  section.data(131).logicalSrcIdx = 166;
	  section.data(131).dtTransOffset = 135;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_jz
	  section.data(132).logicalSrcIdx = 167;
	  section.data(132).dtTransOffset = 136;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_gj
	  section.data(133).logicalSrcIdx = 168;
	  section.data(133).dtTransOffset = 137;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out1_Y0_i
	  section.data(134).logicalSrcIdx = 169;
	  section.data(134).dtTransOffset = 138;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out2_Y0_c
	  section.data(135).logicalSrcIdx = 170;
	  section.data(135).dtTransOffset = 139;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out3_Y0_d
	  section.data(136).logicalSrcIdx = 171;
	  section.data(136).dtTransOffset = 140;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Out4_Y0_c
	  section.data(137).logicalSrcIdx = 172;
	  section.data(137).dtTransOffset = 141;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_ji
	  section.data(138).logicalSrcIdx = 173;
	  section.data(138).dtTransOffset = 142;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_gf
	  section.data(139).logicalSrcIdx = 174;
	  section.data(139).dtTransOffset = 143;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_ov4
	  section.data(140).logicalSrcIdx = 175;
	  section.data(140).dtTransOffset = 144;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_o
	  section.data(141).logicalSrcIdx = 176;
	  section.data(141).dtTransOffset = 145;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant5_Value_n
	  section.data(142).logicalSrcIdx = 177;
	  section.data(142).dtTransOffset = 146;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant6_Value
	  section.data(143).logicalSrcIdx = 178;
	  section.data(143).dtTransOffset = 147;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant4_Value_l
	  section.data(144).logicalSrcIdx = 179;
	  section.data(144).dtTransOffset = 148;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_a
	  section.data(145).logicalSrcIdx = 180;
	  section.data(145).dtTransOffset = 149;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_c0
	  section.data(146).logicalSrcIdx = 181;
	  section.data(146).dtTransOffset = 150;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.SerialReceive1_Protocol
	  section.data(147).logicalSrcIdx = 182;
	  section.data(147).dtTransOffset = 151;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.h_to_subtract_Y0
	  section.data(148).logicalSrcIdx = 183;
	  section.data(148).dtTransOffset = 152;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Outport_Y0
	  section.data(149).logicalSrcIdx = 184;
	  section.data(149).dtTransOffset = 153;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_ab
	  section.data(150).logicalSrcIdx = 185;
	  section.data(150).dtTransOffset = 154;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_b
	  section.data(151).logicalSrcIdx = 186;
	  section.data(151).dtTransOffset = 155;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_js
	  section.data(152).logicalSrcIdx = 187;
	  section.data(152).dtTransOffset = 156;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_hx
	  section.data(153).logicalSrcIdx = 188;
	  section.data(153).dtTransOffset = 157;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.RateTransition_InitialCondition
	  section.data(154).logicalSrcIdx = 189;
	  section.data(154).dtTransOffset = 158;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_jg
	  section.data(155).logicalSrcIdx = 190;
	  section.data(155).dtTransOffset = 159;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_o
	  section.data(156).logicalSrcIdx = 191;
	  section.data(156).dtTransOffset = 160;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory1_InitialCondition_p
	  section.data(157).logicalSrcIdx = 192;
	  section.data(157).dtTransOffset = 161;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch_Threshold_f
	  section.data(158).logicalSrcIdx = 193;
	  section.data(158).dtTransOffset = 162;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_m
	  section.data(159).logicalSrcIdx = 194;
	  section.data(159).dtTransOffset = 163;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_n
	  section.data(160).logicalSrcIdx = 195;
	  section.data(160).dtTransOffset = 164;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_au
	  section.data(161).logicalSrcIdx = 196;
	  section.data(161).dtTransOffset = 165;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_c
	  section.data(162).logicalSrcIdx = 197;
	  section.data(162).dtTransOffset = 166;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_jp
	  section.data(163).logicalSrcIdx = 198;
	  section.data(163).dtTransOffset = 167;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_by
	  section.data(164).logicalSrcIdx = 199;
	  section.data(164).dtTransOffset = 170;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_mz
	  section.data(165).logicalSrcIdx = 200;
	  section.data(165).dtTransOffset = 171;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_kl
	  section.data(166).logicalSrcIdx = 201;
	  section.data(166).dtTransOffset = 172;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain2_Gain
	  section.data(167).logicalSrcIdx = 202;
	  section.data(167).dtTransOffset = 173;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_e
	  section.data(168).logicalSrcIdx = 203;
	  section.data(168).dtTransOffset = 174;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_hxg
	  section.data(169).logicalSrcIdx = 204;
	  section.data(169).dtTransOffset = 175;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_f
	  section.data(170).logicalSrcIdx = 205;
	  section.data(170).dtTransOffset = 176;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_e
	  section.data(171).logicalSrcIdx = 206;
	  section.data(171).dtTransOffset = 177;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_dn
	  section.data(172).logicalSrcIdx = 207;
	  section.data(172).dtTransOffset = 178;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DelayInput2_InitialCondition
	  section.data(173).logicalSrcIdx = 208;
	  section.data(173).dtTransOffset = 179;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.sampletime_WtEt
	  section.data(174).logicalSrcIdx = 209;
	  section.data(174).dtTransOffset = 180;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.alt_r_Value
	  section.data(175).logicalSrcIdx = 210;
	  section.data(175).dtTransOffset = 181;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_bx
	  section.data(176).logicalSrcIdx = 211;
	  section.data(176).dtTransOffset = 182;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.vely_Value
	  section.data(177).logicalSrcIdx = 212;
	  section.data(177).dtTransOffset = 186;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain1_Gain_e
	  section.data(178).logicalSrcIdx = 213;
	  section.data(178).dtTransOffset = 187;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain1_Gain_n
	  section.data(179).logicalSrcIdx = 214;
	  section.data(179).dtTransOffset = 188;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain2_Gain_k
	  section.data(180).logicalSrcIdx = 215;
	  section.data(180).dtTransOffset = 189;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.airspeedgroundspeedaltclimb1_Va
	  section.data(181).logicalSrcIdx = 216;
	  section.data(181).dtTransOffset = 190;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_l
	  section.data(182).logicalSrcIdx = 217;
	  section.data(182).dtTransOffset = 191;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch2_Threshold_a
	  section.data(183).logicalSrcIdx = 218;
	  section.data(183).dtTransOffset = 192;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_c
	  section.data(184).logicalSrcIdx = 219;
	  section.data(184).dtTransOffset = 193;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.USCITAPERCENTUALE_Gain
	  section.data(185).logicalSrcIdx = 220;
	  section.data(185).dtTransOffset = 194;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_bh
	  section.data(186).logicalSrcIdx = 221;
	  section.data(186).dtTransOffset = 195;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain2_Gain_j
	  section.data(187).logicalSrcIdx = 222;
	  section.data(187).dtTransOffset = 196;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_i4
	  section.data(188).logicalSrcIdx = 223;
	  section.data(188).dtTransOffset = 197;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_fj
	  section.data(189).logicalSrcIdx = 224;
	  section.data(189).dtTransOffset = 198;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_h
	  section.data(190).logicalSrcIdx = 225;
	  section.data(190).dtTransOffset = 199;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Integrator_gainval
	  section.data(191).logicalSrcIdx = 226;
	  section.data(191).dtTransOffset = 200;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain1_Gain_jm
	  section.data(192).logicalSrcIdx = 227;
	  section.data(192).dtTransOffset = 201;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_od
	  section.data(193).logicalSrcIdx = 228;
	  section.data(193).dtTransOffset = 202;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_m
	  section.data(194).logicalSrcIdx = 229;
	  section.data(194).dtTransOffset = 203;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_ng
	  section.data(195).logicalSrcIdx = 230;
	  section.data(195).dtTransOffset = 204;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_a
	  section.data(196).logicalSrcIdx = 231;
	  section.data(196).dtTransOffset = 205;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_cr
	  section.data(197).logicalSrcIdx = 232;
	  section.data(197).dtTransOffset = 206;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Integrator_gainval_g
	  section.data(198).logicalSrcIdx = 233;
	  section.data(198).dtTransOffset = 207;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_i
	  section.data(199).logicalSrcIdx = 234;
	  section.data(199).dtTransOffset = 208;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteWashoutFilter_NumCoef
	  section.data(200).logicalSrcIdx = 235;
	  section.data(200).dtTransOffset = 209;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteWashoutFilter_DenCoef
	  section.data(201).logicalSrcIdx = 236;
	  section.data(201).dtTransOffset = 211;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.DiscreteWashoutFilter_InitialSt
	  section.data(202).logicalSrcIdx = 237;
	  section.data(202).dtTransOffset = 213;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_bh
	  section.data(203).logicalSrcIdx = 238;
	  section.data(203).dtTransOffset = 214;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_pa
	  section.data(204).logicalSrcIdx = 239;
	  section.data(204).dtTransOffset = 215;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_b
	  section.data(205).logicalSrcIdx = 240;
	  section.data(205).dtTransOffset = 218;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_jr
	  section.data(206).logicalSrcIdx = 241;
	  section.data(206).dtTransOffset = 219;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Saturation_UpperSat
	  section.data(207).logicalSrcIdx = 242;
	  section.data(207).dtTransOffset = 220;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Saturation_LowerSat
	  section.data(208).logicalSrcIdx = 243;
	  section.data(208).dtTransOffset = 221;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PatohPa_Gain
	  section.data(209).logicalSrcIdx = 244;
	  section.data(209).dtTransOffset = 222;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_jt
	  section.data(210).logicalSrcIdx = 245;
	  section.data(210).dtTransOffset = 223;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PatohPa1_Gain
	  section.data(211).logicalSrcIdx = 246;
	  section.data(211).dtTransOffset = 224;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.RC_default_Value
	  section.data(212).logicalSrcIdx = 247;
	  section.data(212).dtTransOffset = 225;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_g
	  section.data(213).logicalSrcIdx = 248;
	  section.data(213).dtTransOffset = 226;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_jf
	  section.data(214).logicalSrcIdx = 249;
	  section.data(214).dtTransOffset = 227;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant6_Value_a
	  section.data(215).logicalSrcIdx = 250;
	  section.data(215).dtTransOffset = 228;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant4_Value_k
	  section.data(216).logicalSrcIdx = 251;
	  section.data(216).dtTransOffset = 229;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_m
	  section.data(217).logicalSrcIdx = 252;
	  section.data(217).dtTransOffset = 230;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_nb
	  section.data(218).logicalSrcIdx = 253;
	  section.data(218).dtTransOffset = 231;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant7_Value
	  section.data(219).logicalSrcIdx = 254;
	  section.data(219).dtTransOffset = 232;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_e
	  section.data(220).logicalSrcIdx = 255;
	  section.data(220).dtTransOffset = 233;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant5_Value_i
	  section.data(221).logicalSrcIdx = 256;
	  section.data(221).dtTransOffset = 234;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant2_Value_l
	  section.data(222).logicalSrcIdx = 257;
	  section.data(222).dtTransOffset = 235;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.HitCrossing_Offset
	  section.data(223).logicalSrcIdx = 258;
	  section.data(223).dtTransOffset = 236;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain_Gain_je
	  section.data(224).logicalSrcIdx = 259;
	  section.data(224).dtTransOffset = 237;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator_Amp
	  section.data(225).logicalSrcIdx = 260;
	  section.data(225).dtTransOffset = 238;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator_Period
	  section.data(226).logicalSrcIdx = 261;
	  section.data(226).dtTransOffset = 239;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator_Duty
	  section.data(227).logicalSrcIdx = 262;
	  section.data(227).dtTransOffset = 240;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator_PhaseDelay
	  section.data(228).logicalSrcIdx = 263;
	  section.data(228).dtTransOffset = 241;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator1_Amp
	  section.data(229).logicalSrcIdx = 264;
	  section.data(229).dtTransOffset = 242;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator1_Period
	  section.data(230).logicalSrcIdx = 265;
	  section.data(230).dtTransOffset = 243;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator1_Duty
	  section.data(231).logicalSrcIdx = 266;
	  section.data(231).dtTransOffset = 244;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.PulseGenerator1_PhaseDelay
	  section.data(232).logicalSrcIdx = 267;
	  section.data(232).dtTransOffset = 245;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant4_Value_a
	  section.data(233).logicalSrcIdx = 268;
	  section.data(233).dtTransOffset = 246;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant5_Value_a
	  section.data(234).logicalSrcIdx = 269;
	  section.data(234).dtTransOffset = 247;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory2_InitialCondition_o
	  section.data(235).logicalSrcIdx = 270;
	  section.data(235).dtTransOffset = 248;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch1_Threshold_c
	  section.data(236).logicalSrcIdx = 271;
	  section.data(236).dtTransOffset = 249;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant_Value_gw
	  section.data(1).logicalSrcIdx = 272;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.T_Y0
	  section.data(1).logicalSrcIdx = 273;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.T_0_Y0
	  section.data(2).logicalSrcIdx = 274;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch_Threshold_p
	  section.data(3).logicalSrcIdx = 275;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.p_Y0
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant7_Value_h
	  section.data(2).logicalSrcIdx = 277;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant10_Value
	  section.data(3).logicalSrcIdx = 278;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant11_Value
	  section.data(4).logicalSrcIdx = 279;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant8_Value_e
	  section.data(5).logicalSrcIdx = 280;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant9_Value
	  section.data(6).logicalSrcIdx = 281;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.onboard_control_sensor_presentu
	  section.data(7).logicalSrcIdx = 282;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Switch_Threshold_m
	  section.data(1).logicalSrcIdx = 283;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain1_Gain_eu
	  section.data(2).logicalSrcIdx = 284;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_at
	  section.data(1).logicalSrcIdx = 285;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.loaduint16_Value
	  section.data(2).logicalSrcIdx = 286;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P._Value
	  section.data(3).logicalSrcIdx = 287;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_g
	  section.data(4).logicalSrcIdx = 288;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.UnitDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 289;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant3_Value_ok
	  section.data(2).logicalSrcIdx = 290;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Gain3_Gain
	  section.data(1).logicalSrcIdx = 291;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_j
	  section.data(1).logicalSrcIdx = 292;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory1_InitialCondition_g
	  section.data(2).logicalSrcIdx = 293;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory2_InitialCondition_n
	  section.data(3).logicalSrcIdx = 294;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory6_InitialCondition
	  section.data(4).logicalSrcIdx = 295;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.mario_Y0
	  section.data(5).logicalSrcIdx = 296;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory4_InitialCondition_g
	  section.data(6).logicalSrcIdx = 297;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Constant1_Value_a
	  section.data(7).logicalSrcIdx = 298;
	  section.data(7).dtTransOffset = 305;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.SIUAVuint8_Value
	  section.data(8).logicalSrcIdx = 299;
	  section.data(8).dtTransOffset = 306;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory5_InitialCondition_d
	  section.data(9).logicalSrcIdx = 300;
	  section.data(9).dtTransOffset = 307;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory1_InitialCondition_b
	  section.data(10).logicalSrcIdx = 301;
	  section.data(10).dtTransOffset = 308;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory_InitialCondition_o
	  section.data(11).logicalSrcIdx = 302;
	  section.data(11).dtTransOffset = 309;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory3_InitialCondition_c
	  section.data(12).logicalSrcIdx = 303;
	  section.data(12).dtTransOffset = 310;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Memory2_InitialCondition_g
	  section.data(13).logicalSrcIdx = 304;
	  section.data(13).dtTransOffset = 311;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.Typefixed_wingAutopilotgeneric_
	  section.data(14).logicalSrcIdx = 305;
	  section.data(14).dtTransOffset = 320;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.BitwiseOperator1_BitMask
	  section.data(1).logicalSrcIdx = 306;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.I2CRead12_SampleTime
	  section.data(1).logicalSrcIdx = 307;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_T2_Y0
	  section.data(1).logicalSrcIdx = 308;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_T3_Y0
	  section.data(2).logicalSrcIdx = 309;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p2_Y0
	  section.data(3).logicalSrcIdx = 310;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p3_Y0
	  section.data(4).logicalSrcIdx = 311;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p4_Y0
	  section.data(5).logicalSrcIdx = 312;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p5_Y0
	  section.data(6).logicalSrcIdx = 313;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p6_Y0
	  section.data(7).logicalSrcIdx = 314;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p7_Y0
	  section.data(8).logicalSrcIdx = 315;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p8_Y0
	  section.data(9).logicalSrcIdx = 316;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p9_Y0
	  section.data(10).logicalSrcIdx = 317;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_T1_Y0
	  section.data(1).logicalSrcIdx = 318;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.dig_p1_Y0
	  section.data(2).logicalSrcIdx = 319;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.pwm_max_min_Y0
	  section.data(3).logicalSrcIdx = 320;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.registromemoria2_Value
	  section.data(4).logicalSrcIdx = 321;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.Constant1_Value
	  section.data(1).logicalSrcIdx = 322;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.One_time_initialization.Constant4_Value
	  section.data(2).logicalSrcIdx = 323;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.ResettableSubsystem_o.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 324;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__P.ResettableSubsystem.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 325;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
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
    nTotSects     = 17;
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
    ;% Auto data (PROVA_FINALE_LOAD_ARDUINO_15__B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion_a
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Constant2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Go_Home
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Abs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.ComplextoRealImag
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.h_goHome
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.QUOTA
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Gain_g
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Px
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Abs1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory5
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.QUOTA_m
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.In
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Sum2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 25;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.maneuver_selector
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 26;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.trig_approach
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 27;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.trig_flare
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 28;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.approach_selector
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 29;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.h_Home
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 30;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Multiply
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 31;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.x_f_out
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 32;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.h_f_out
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 33;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.k_x_out
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 34;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.h_c_out
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 35;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.no_solution
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 36;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.counter_out
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 37;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.h_vett
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 38;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.In_g
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 39;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.In_k
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 40;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Fase_ATO
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 41;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.eq_rot
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 42;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.h_ref
	  section.data(35).logicalSrcIdx = 39;
	  section.data(35).dtTransOffset = 43;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.psi_ref_selector
	  section.data(36).logicalSrcIdx = 42;
	  section.data(36).dtTransOffset = 44;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.theta_ground_selector
	  section.data(37).logicalSrcIdx = 43;
	  section.data(37).dtTransOffset = 45;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Switch
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 46;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Switch_AL
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 47;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Switch_l
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 48;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Switch_a
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 49;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.switch_manetta
	  section.data(42).logicalSrcIdx = 53;
	  section.data(42).dtTransOffset = 50;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.switch_equilibratore
	  section.data(43).logicalSrcIdx = 54;
	  section.data(43).dtTransOffset = 51;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.switch_alettoni
	  section.data(44).logicalSrcIdx = 55;
	  section.data(44).dtTransOffset = 52;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.switch_timone
	  section.data(45).logicalSrcIdx = 56;
	  section.data(45).dtTransOffset = 53;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.modo
	  section.data(46).logicalSrcIdx = 60;
	  section.data(46).dtTransOffset = 54;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.test
	  section.data(47).logicalSrcIdx = 63;
	  section.data(47).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o8
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o10
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o13
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o17
	  section.data(4).logicalSrcIdx = 73;
	  section.data(4).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Switch1
	  section.data(5).logicalSrcIdx = 74;
	  section.data(5).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion1_c
	  section.data(6).logicalSrcIdx = 75;
	  section.data(6).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.AGAC
	  section.data(7).logicalSrcIdx = 76;
	  section.data(7).dtTransOffset = 17;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion2
	  section.data(8).logicalSrcIdx = 77;
	  section.data(8).dtTransOffset = 21;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion_l
	  section.data(9).logicalSrcIdx = 78;
	  section.data(9).dtTransOffset = 22;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion1_g
	  section.data(10).logicalSrcIdx = 79;
	  section.data(10).dtTransOffset = 23;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.T
	  section.data(11).logicalSrcIdx = 80;
	  section.data(11).dtTransOffset = 24;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder_o1
	  section.data(12).logicalSrcIdx = 81;
	  section.data(12).dtTransOffset = 25;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.WP_param
	  section.data(13).logicalSrcIdx = 82;
	  section.data(13).dtTransOffset = 26;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Val_out_MAV
	  section.data(14).logicalSrcIdx = 83;
	  section.data(14).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder_o2
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Add
	  section.data(2).logicalSrcIdx = 85;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion1_i
	  section.data(3).logicalSrcIdx = 87;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion_ay
	  section.data(4).logicalSrcIdx = 88;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder_o2_a
	  section.data(5).logicalSrcIdx = 89;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Heading
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o2
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion3
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 66;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder1
	  section.data(4).logicalSrcIdx = 67;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.ByteUnpack_o2
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.ByteReversal
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o7
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o9
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o11
	  section.data(3).logicalSrcIdx = 93;
	  section.data(3).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.TmpSignalConversionAtSFunctionI
	  section.data(4).logicalSrcIdx = 94;
	  section.data(4).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion2_h
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Throttle
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory_a
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o3
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o4
	  section.data(5).logicalSrcIdx = 100;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.WP_info
	  section.data(6).logicalSrcIdx = 101;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.new_mex
	  section.data(7).logicalSrcIdx = 102;
	  section.data(7).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.GC_info
	  section.data(8).logicalSrcIdx = 103;
	  section.data(8).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Gain1
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion_ld
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion1_p
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Heading_g
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 13;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.PWM_throttle
	  section.data(5).logicalSrcIdx = 108;
	  section.data(5).dtTransOffset = 14;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder2
	  section.data(6).logicalSrcIdx = 109;
	  section.data(6).dtTransOffset = 15;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.PWM_elevator
	  section.data(7).logicalSrcIdx = 110;
	  section.data(7).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.PWM_aileron
	  section.data(8).logicalSrcIdx = 111;
	  section.data(8).dtTransOffset = 17;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.PWM_rudder
	  section.data(9).logicalSrcIdx = 112;
	  section.data(9).dtTransOffset = 18;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion2_m
	  section.data(10).logicalSrcIdx = 113;
	  section.data(10).dtTransOffset = 19;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion1_cs
	  section.data(11).logicalSrcIdx = 114;
	  section.data(11).dtTransOffset = 20;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Sum
	  section.data(12).logicalSrcIdx = 115;
	  section.data(12).dtTransOffset = 21;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion2_j
	  section.data(13).logicalSrcIdx = 116;
	  section.data(13).dtTransOffset = 22;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.DataTypeConversion_p
	  section.data(14).logicalSrcIdx = 117;
	  section.data(14).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.ByteUnpack_o1
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 41;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o5
	  section.data(3).logicalSrcIdx = 128;
	  section.data(3).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.ByteUnpack_o3
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunctionBuilder_o1_h
	  section.data(2).logicalSrcIdx = 121;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory1_p
	  section.data(3).logicalSrcIdx = 122;
	  section.data(3).dtTransOffset = 101;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory_k
	  section.data(4).logicalSrcIdx = 123;
	  section.data(4).dtTransOffset = 103;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Memory3
	  section.data(5).logicalSrcIdx = 124;
	  section.data(5).dtTransOffset = 107;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o1
	  section.data(6).logicalSrcIdx = 125;
	  section.data(6).dtTransOffset = 108;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o3_j
	  section.data(7).logicalSrcIdx = 126;
	  section.data(7).dtTransOffset = 112;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o4_n
	  section.data(8).logicalSrcIdx = 127;
	  section.data(8).dtTransOffset = 113;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o6
	  section.data(9).logicalSrcIdx = 129;
	  section.data(9).dtTransOffset = 115;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o12
	  section.data(10).logicalSrcIdx = 130;
	  section.data(10).dtTransOffset = 116;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o14
	  section.data(11).logicalSrcIdx = 131;
	  section.data(11).dtTransOffset = 117;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o15
	  section.data(12).logicalSrcIdx = 132;
	  section.data(12).dtTransOffset = 118;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o16
	  section.data(13).logicalSrcIdx = 133;
	  section.data(13).dtTransOffset = 119;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.TmpSignalConversionAtSFunctio_m
	  section.data(14).logicalSrcIdx = 134;
	  section.data(14).dtTransOffset = 120;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o1_j
	  section.data(15).logicalSrcIdx = 135;
	  section.data(15).dtTransOffset = 124;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.SFunction_o2_f
	  section.data(16).logicalSrcIdx = 136;
	  section.data(16).dtTransOffset = 125;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.iflogic
	  section.data(17).logicalSrcIdx = 137;
	  section.data(17).dtTransOffset = 389;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.mess_out
	  section.data(18).logicalSrcIdx = 139;
	  section.data(18).dtTransOffset = 390;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.AP_int
	  section.data(19).logicalSrcIdx = 140;
	  section.data(19).dtTransOffset = 490;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.B_Remaining
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.Ap_sel
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.HitCrossing
	  section.data(2).logicalSrcIdx = 143;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.ByteUnpack
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead3
	  section.data(2).logicalSrcIdx = 145;
	  section.data(2).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead
	  section.data(3).logicalSrcIdx = 146;
	  section.data(3).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead9
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead8
	  section.data(2).logicalSrcIdx = 148;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead7
	  section.data(3).logicalSrcIdx = 149;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead6
	  section.data(4).logicalSrcIdx = 150;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead5
	  section.data(5).logicalSrcIdx = 151;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead4
	  section.data(6).logicalSrcIdx = 152;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead2
	  section.data(7).logicalSrcIdx = 153;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead11
	  section.data(8).logicalSrcIdx = 154;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead10
	  section.data(9).logicalSrcIdx = 155;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead1
	  section.data(10).logicalSrcIdx = 156;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15__B.One_time_initialization.I2CRead12
	  section.data(1).logicalSrcIdx = 157;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
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
    sectIdxOffset = 17;
    
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
    ;% Auto data (PROVA_FINALE_LOAD_ARDUINO_15_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.obj_f
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.obj_p
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.obj_e
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.obj_b
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.obj_d
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder_DSTATE
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder_DSTATE_l
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.DelayInput2_DSTATE
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Integrator_DSTATE
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Integrator_DSTATE_p
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.DiscreteWashoutFilter_states
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder10_DSTATE
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder4_DSTATE
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder5_DSTATE
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder9_DSTATE
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SFunctionBuilder_DSTATE_n
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.RateTransition_Buffer0
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 12;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory1_PreviousInput
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 13;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 14;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory2_PreviousInput
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 15;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput_l
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.P_ref
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 25;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.rl_up
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 26;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.rl_dw
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 27;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.flag
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 28;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory4_PreviousInput
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 29;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.flag_m
	  section.data(23).logicalSrcIdx = 29;
	  section.data(23).dtTransOffset = 30;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.lat1
	  section.data(24).logicalSrcIdx = 30;
	  section.data(24).dtTransOffset = 31;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.long1
	  section.data(25).logicalSrcIdx = 31;
	  section.data(25).dtTransOffset = 32;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory7_PreviousInput
	  section.data(26).logicalSrcIdx = 32;
	  section.data(26).dtTransOffset = 33;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory5_PreviousInput
	  section.data(27).logicalSrcIdx = 33;
	  section.data(27).dtTransOffset = 34;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory1_PreviousInput_l
	  section.data(28).logicalSrcIdx = 34;
	  section.data(28).dtTransOffset = 35;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory2_PreviousInput_f
	  section.data(29).logicalSrcIdx = 35;
	  section.data(29).dtTransOffset = 36;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.x
	  section.data(30).logicalSrcIdx = 36;
	  section.data(30).dtTransOffset = 37;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.cycle_count
	  section.data(31).logicalSrcIdx = 37;
	  section.data(31).dtTransOffset = 41;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.eps
	  section.data(32).logicalSrcIdx = 38;
	  section.data(32).dtTransOffset = 42;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.flag_c
	  section.data(33).logicalSrcIdx = 39;
	  section.data(33).dtTransOffset = 46;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory3_PreviousInput
	  section.data(34).logicalSrcIdx = 40;
	  section.data(34).dtTransOffset = 47;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.ALT_ref
	  section.data(35).logicalSrcIdx = 42;
	  section.data(35).dtTransOffset = 48;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput_i
	  section.data(36).logicalSrcIdx = 44;
	  section.data(36).dtTransOffset = 49;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory1_PreviousInput_o
	  section.data(37).logicalSrcIdx = 45;
	  section.data(37).dtTransOffset = 50;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.alarm
	  section.data(38).logicalSrcIdx = 46;
	  section.data(38).dtTransOffset = 51;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput_h
	  section.data(39).logicalSrcIdx = 47;
	  section.data(39).dtTransOffset = 52;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.mess_len
	  section.data(40).logicalSrcIdx = 49;
	  section.data(40).dtTransOffset = 53;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.test1
	  section.data(41).logicalSrcIdx = 50;
	  section.data(41).dtTransOffset = 54;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.riferimenti
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.WP_dbP
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.WP_dbP_AL
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.clockTickCounter_c
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_c10_PROVA_FINALE_LOAD_ARDUIN
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_c1_PROVA_FINALE_LOAD_ARDUINO
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_c21_PROVA_FINALE_LOAD_ARDUIN
	  section.data(3).logicalSrcIdx = 65;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_c26_PROVA_FINALE_LOAD_ARDUIN
	  section.data(4).logicalSrcIdx = 66;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_AUTOMATICA
	  section.data(5).logicalSrcIdx = 67;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_c23_PROVA_FINALE_LOAD_ARDUIN
	  section.data(6).logicalSrcIdx = 68;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_c9_PROVA_FINALE_LOAD_ARDUINO
	  section.data(7).logicalSrcIdx = 69;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.HitCrossing_MODE
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput_ic
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput_n
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.counter
	  section.data(3).logicalSrcIdx = 73;
	  section.data(3).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.WP_dbI
	  section.data(4).logicalSrcIdx = 74;
	  section.data(4).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Integrator_PrevResetState
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem2_SubsysRanBC
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 78;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem1_SubsysRanBC
	  section.data(4).logicalSrcIdx = 79;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem1_SubsysRanBC_n
	  section.data(5).logicalSrcIdx = 80;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Execution_loop_SubsysRanBC
	  section.data(6).logicalSrcIdx = 81;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem3_SubsysRanBC
	  section.data(7).logicalSrcIdx = 82;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem2_SubsysRanBC_c
	  section.data(8).logicalSrcIdx = 83;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem1_SubsysRanBC_p
	  section.data(9).logicalSrcIdx = 84;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SampleandHold_SubsysRanBC
	  section.data(10).logicalSrcIdx = 85;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.INSEGUIMENTOCENTROPISTA_SubsysR
	  section.data(11).logicalSrcIdx = 86;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.FLARE_SubsysRanBC
	  section.data(12).logicalSrcIdx = 87;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.APPROACH_SubsysRanBC
	  section.data(13).logicalSrcIdx = 88;
	  section.data(13).dtTransOffset = 12;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(14).logicalSrcIdx = 89;
	  section.data(14).dtTransOffset = 13;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Subsystem_SubsysRanBC_h
	  section.data(15).logicalSrcIdx = 90;
	  section.data(15).dtTransOffset = 14;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.DECOLLOAUTOMATICO_SubsysRanBC
	  section.data(16).logicalSrcIdx = 91;
	  section.data(16).dtTransOffset = 15;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SampleandHold1_SubsysRanBC
	  section.data(17).logicalSrcIdx = 92;
	  section.data(17).dtTransOffset = 16;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.SampleandHold_SubsysRanBC_h
	  section.data(18).logicalSrcIdx = 93;
	  section.data(18).dtTransOffset = 17;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enabled_SubsysRanBC
	  section.data(19).logicalSrcIdx = 94;
	  section.data(19).dtTransOffset = 18;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enabled_SubsysRanBC_p
	  section.data(20).logicalSrcIdx = 95;
	  section.data(20).dtTransOffset = 19;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enabled_SubsysRanBC_o
	  section.data(21).logicalSrcIdx = 96;
	  section.data(21).dtTransOffset = 20;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.EnabledSubsystem_SubsysRanBC
	  section.data(22).logicalSrcIdx = 97;
	  section.data(22).dtTransOffset = 21;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.EnabledSubsystem_SubsysRanBC_c
	  section.data(23).logicalSrcIdx = 98;
	  section.data(23).dtTransOffset = 22;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.EnabledSubsystem_SubsysRanBC_h
	  section.data(24).logicalSrcIdx = 99;
	  section.data(24).dtTransOffset = 23;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enable_SubsysRanBC
	  section.data(25).logicalSrcIdx = 100;
	  section.data(25).dtTransOffset = 24;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.sendbyte_SubsysRanBC
	  section.data(26).logicalSrcIdx = 101;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory4_PreviousInput_c
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory5_PreviousInput_l
	  section.data(2).logicalSrcIdx = 103;
	  section.data(2).dtTransOffset = 300;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory1_PreviousInput_d
	  section.data(3).logicalSrcIdx = 104;
	  section.data(3).dtTransOffset = 400;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory_PreviousInput_h5
	  section.data(4).logicalSrcIdx = 105;
	  section.data(4).dtTransOffset = 402;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory3_PreviousInput_o
	  section.data(5).logicalSrcIdx = 106;
	  section.data(5).dtTransOffset = 406;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory2_PreviousInput_a
	  section.data(6).logicalSrcIdx = 107;
	  section.data(6).dtTransOffset = 407;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.message
	  section.data(7).logicalSrcIdx = 108;
	  section.data(7).dtTransOffset = 416;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.counter_k
	  section.data(8).logicalSrcIdx = 109;
	  section.data(8).dtTransOffset = 496;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_active_c10_PROVA_FINALE_LOAD
	  section.data(9).logicalSrcIdx = 110;
	  section.data(9).dtTransOffset = 497;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory1_PreviousInput_h
	  section.data(10).logicalSrcIdx = 112;
	  section.data(10).dtTransOffset = 498;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Memory6_PreviousInput
	  section.data(11).logicalSrcIdx = 114;
	  section.data(11).dtTransOffset = 499;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_active_c1_PROVA_FINALE_LOAD_
	  section.data(12).logicalSrcIdx = 115;
	  section.data(12).dtTransOffset = 500;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.temporalCounter_i1
	  section.data(13).logicalSrcIdx = 116;
	  section.data(13).dtTransOffset = 501;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_active_c21_PROVA_FINALE_LOAD
	  section.data(14).logicalSrcIdx = 117;
	  section.data(14).dtTransOffset = 502;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_active_c26_PROVA_FINALE_LOAD
	  section.data(15).logicalSrcIdx = 118;
	  section.data(15).dtTransOffset = 503;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_active_c23_PROVA_FINALE_LOAD
	  section.data(16).logicalSrcIdx = 119;
	  section.data(16).dtTransOffset = 504;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.is_active_c9_PROVA_FINALE_LOAD_
	  section.data(17).logicalSrcIdx = 120;
	  section.data(17).dtTransOffset = 505;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.i
	  section.data(18).logicalSrcIdx = 121;
	  section.data(18).dtTransOffset = 506;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.message_i
	  section.data(19).logicalSrcIdx = 122;
	  section.data(19).dtTransOffset = 507;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.counter_a
	  section.data(20).logicalSrcIdx = 123;
	  section.data(20).dtTransOffset = 607;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.start_found
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.end_found
	  section.data(2).logicalSrcIdx = 125;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.x_not_empty
	  section.data(3).logicalSrcIdx = 131;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.x_new_not_empty
	  section.data(4).logicalSrcIdx = 132;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.cycle_count_not_empty
	  section.data(5).logicalSrcIdx = 133;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.eps_not_empty
	  section.data(6).logicalSrcIdx = 134;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Tf_not_empty
	  section.data(7).logicalSrcIdx = 135;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Interr_parz
	  section.data(8).logicalSrcIdx = 137;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.WP_dbP_not_empty
	  section.data(9).logicalSrcIdx = 138;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.WP_dbP_AL_not_empty
	  section.data(10).logicalSrcIdx = 139;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enabled_MODE
	  section.data(11).logicalSrcIdx = 140;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enabled_MODE_g
	  section.data(12).logicalSrcIdx = 141;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.Enabled_MODE_m
	  section.data(13).logicalSrcIdx = 142;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_i
	  section.data(2).logicalSrcIdx = 144;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_c
	  section.data(3).logicalSrcIdx = 145;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_b
	  section.data(4).logicalSrcIdx = 146;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_k
	  section.data(5).logicalSrcIdx = 147;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_co
	  section.data(6).logicalSrcIdx = 148;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_k4
	  section.data(7).logicalSrcIdx = 149;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_d
	  section.data(8).logicalSrcIdx = 150;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_ir
	  section.data(9).logicalSrcIdx = 151;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_l
	  section.data(10).logicalSrcIdx = 152;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_d0
	  section.data(11).logicalSrcIdx = 153;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_o
	  section.data(12).logicalSrcIdx = 154;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_kf
	  section.data(13).logicalSrcIdx = 155;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_d01
	  section.data(1).logicalSrcIdx = 156;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_in
	  section.data(2).logicalSrcIdx = 157;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.obj_j
	  section.data(3).logicalSrcIdx = 158;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.One_time_initialization.One_time_initialization_SubsysR
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.ResettableSubsystem_o.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 176;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PROVA_FINALE_LOAD_ARDUINO_15_DW.ResettableSubsystem.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 177;
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


  targMap.checksum0 = 992925205;
  targMap.checksum1 = 2438383341;
  targMap.checksum2 = 4017163700;
  targMap.checksum3 = 1553216923;

