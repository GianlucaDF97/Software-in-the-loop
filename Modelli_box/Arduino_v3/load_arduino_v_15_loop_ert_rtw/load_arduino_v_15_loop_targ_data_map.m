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
    ;% Auto data (load_arduino_v_15_loop_P)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Kp_comp_h
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Amax
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Amin
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Emax
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Emin
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Rmax
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Rmin
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Tmax
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_P.attuatore_Tmin
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_P.interventoA_05
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_P.interventoA_1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_P.interventoE_05
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_P.interventoE_1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_P.interventoT
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_P.inv_A
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_P.inv_E
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_loop_P.inv_R
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_P.inv_comp_h
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_loop_P.phi_max
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_P.phi_min
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_P.safe_V
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_loop_P.safe_phi
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_loop_P.t_AP
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_loop_P.theta_max
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_loop_P.theta_min
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_loop_P.time_alarm_SAFE
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_loop_P.vel_wp1_al
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_P.vel_wp2_al
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Ki_becch
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.Ki_roll
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.Kp_becch
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.Kp_imb
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.Kp_p
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_P.Kp_q
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_P.Kp_roll
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.K_imb_inv
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 251;
      section.data(251)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.PIDController_InitialConditionF
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.PIDController_InitialConditio_d
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.PIDController_Kb
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.PIDController_Kb_k
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.PIDController_Kt
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_P.PIDController_Kt_m
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_P.CompareToConstant_const
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_P.CompareToConstant_const_d
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_P.CompareToConstant_const_p
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_P.CompareToConstant_const_b
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_P.CompareToConstant_const_dp
	  section.data(11).logicalSrcIdx = 46;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_P.CompareToConstant_const_g
	  section.data(12).logicalSrcIdx = 47;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_P.SerialTransmit_Protocol
	  section.data(13).logicalSrcIdx = 48;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value
	  section.data(14).logicalSrcIdx = 49;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_P.Out1_Y0
	  section.data(15).logicalSrcIdx = 50;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_P.Constant5_Value
	  section.data(16).logicalSrcIdx = 51;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_loop_P.Switch1_Threshold
	  section.data(17).logicalSrcIdx = 52;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_P.r_rif_Value
	  section.data(18).logicalSrcIdx = 53;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value
	  section.data(19).logicalSrcIdx = 54;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_k
	  section.data(20).logicalSrcIdx = 55;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_P.u0_Y0
	  section.data(21).logicalSrcIdx = 56;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_loop_P.Switch_Threshold
	  section.data(22).logicalSrcIdx = 57;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_e
	  section.data(23).logicalSrcIdx = 58;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_n
	  section.data(24).logicalSrcIdx = 59;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_loop_P.u0_Y0_i
	  section.data(25).logicalSrcIdx = 60;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_loop_P.Switch_Threshold_g
	  section.data(26).logicalSrcIdx = 61;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_loop_P.Alarm_Int_Y0
	  section.data(27).logicalSrcIdx = 62;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_P.Alarm_Int_Y0_j
	  section.data(28).logicalSrcIdx = 63;
	  section.data(28).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value
	  section.data(29).logicalSrcIdx = 64;
	  section.data(29).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_i
	  section.data(30).logicalSrcIdx = 65;
	  section.data(30).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_loop_P.AlarmSafe_Y0
	  section.data(31).logicalSrcIdx = 66;
	  section.data(31).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition
	  section.data(32).logicalSrcIdx = 67;
	  section.data(32).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_d
	  section.data(33).logicalSrcIdx = 68;
	  section.data(33).dtTransOffset = 32;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain
	  section.data(34).logicalSrcIdx = 69;
	  section.data(34).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_i
	  section.data(35).logicalSrcIdx = 70;
	  section.data(35).dtTransOffset = 34;
	
	  ;% load_arduino_v_15_loop_P._Y0
	  section.data(36).logicalSrcIdx = 71;
	  section.data(36).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_loop_P._Y0_a
	  section.data(37).logicalSrcIdx = 72;
	  section.data(37).dtTransOffset = 36;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_g
	  section.data(38).logicalSrcIdx = 73;
	  section.data(38).dtTransOffset = 37;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_a
	  section.data(39).logicalSrcIdx = 74;
	  section.data(39).dtTransOffset = 38;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_m
	  section.data(40).logicalSrcIdx = 75;
	  section.data(40).dtTransOffset = 39;
	
	  ;% load_arduino_v_15_loop_P.Memory1_InitialCondition
	  section.data(41).logicalSrcIdx = 76;
	  section.data(41).dtTransOffset = 40;
	
	  ;% load_arduino_v_15_loop_P.Out1_Y0_d
	  section.data(42).logicalSrcIdx = 77;
	  section.data(42).dtTransOffset = 41;
	
	  ;% load_arduino_v_15_loop_P.Out2_Y0
	  section.data(43).logicalSrcIdx = 78;
	  section.data(43).dtTransOffset = 42;
	
	  ;% load_arduino_v_15_loop_P.Out3_Y0
	  section.data(44).logicalSrcIdx = 79;
	  section.data(44).dtTransOffset = 43;
	
	  ;% load_arduino_v_15_loop_P.Out4_Y0
	  section.data(45).logicalSrcIdx = 80;
	  section.data(45).dtTransOffset = 44;
	
	  ;% load_arduino_v_15_loop_P.Memory3_InitialCondition
	  section.data(46).logicalSrcIdx = 81;
	  section.data(46).dtTransOffset = 45;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_e
	  section.data(47).logicalSrcIdx = 82;
	  section.data(47).dtTransOffset = 46;
	
	  ;% load_arduino_v_15_loop_P.h_ref_Y0
	  section.data(48).logicalSrcIdx = 83;
	  section.data(48).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_loop_P.flare_data_Y0
	  section.data(49).logicalSrcIdx = 84;
	  section.data(49).dtTransOffset = 48;
	
	  ;% load_arduino_v_15_loop_P.landing_abort_Y0
	  section.data(50).logicalSrcIdx = 85;
	  section.data(50).dtTransOffset = 49;
	
	  ;% load_arduino_v_15_loop_P.rc_ref_app_Y0
	  section.data(51).logicalSrcIdx = 86;
	  section.data(51).dtTransOffset = 50;
	
	  ;% load_arduino_v_15_loop_P.x_g0_Value
	  section.data(52).logicalSrcIdx = 87;
	  section.data(52).dtTransOffset = 51;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value
	  section.data(53).logicalSrcIdx = 88;
	  section.data(53).dtTransOffset = 52;
	
	  ;% load_arduino_v_15_loop_P.Constant4_Value
	  section.data(54).logicalSrcIdx = 89;
	  section.data(54).dtTransOffset = 53;
	
	  ;% load_arduino_v_15_loop_P.DiscreteTimeIntegrator_gainval
	  section.data(55).logicalSrcIdx = 90;
	  section.data(55).dtTransOffset = 54;
	
	  ;% load_arduino_v_15_loop_P.DiscreteTimeIntegrator_IC
	  section.data(56).logicalSrcIdx = 91;
	  section.data(56).dtTransOffset = 55;
	
	  ;% load_arduino_v_15_loop_P.DiscreteTimeIntegrator_UpperSat
	  section.data(57).logicalSrcIdx = 92;
	  section.data(57).dtTransOffset = 56;
	
	  ;% load_arduino_v_15_loop_P.DiscreteTimeIntegrator_LowerSat
	  section.data(58).logicalSrcIdx = 93;
	  section.data(58).dtTransOffset = 57;
	
	  ;% load_arduino_v_15_loop_P.Switch_Threshold_b
	  section.data(59).logicalSrcIdx = 94;
	  section.data(59).dtTransOffset = 58;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_e0
	  section.data(60).logicalSrcIdx = 95;
	  section.data(60).dtTransOffset = 59;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_g
	  section.data(61).logicalSrcIdx = 96;
	  section.data(61).dtTransOffset = 60;
	
	  ;% load_arduino_v_15_loop_P.h_ref_Y0_n
	  section.data(62).logicalSrcIdx = 97;
	  section.data(62).dtTransOffset = 61;
	
	  ;% load_arduino_v_15_loop_P.RC_ref_Y0
	  section.data(63).logicalSrcIdx = 98;
	  section.data(63).dtTransOffset = 62;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_j
	  section.data(64).logicalSrcIdx = 99;
	  section.data(64).dtTransOffset = 63;
	
	  ;% load_arduino_v_15_loop_P.psi_ref_landing_Y0
	  section.data(65).logicalSrcIdx = 100;
	  section.data(65).dtTransOffset = 64;
	
	  ;% load_arduino_v_15_loop_P.Bias_Bias
	  section.data(66).logicalSrcIdx = 101;
	  section.data(66).dtTransOffset = 65;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_b
	  section.data(67).logicalSrcIdx = 102;
	  section.data(67).dtTransOffset = 66;
	
	  ;% load_arduino_v_15_loop_P.Bias1_Bias
	  section.data(68).logicalSrcIdx = 103;
	  section.data(68).dtTransOffset = 67;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_i
	  section.data(69).logicalSrcIdx = 104;
	  section.data(69).dtTransOffset = 68;
	
	  ;% load_arduino_v_15_loop_P.Bias_Bias_n
	  section.data(70).logicalSrcIdx = 105;
	  section.data(70).dtTransOffset = 69;
	
	  ;% load_arduino_v_15_loop_P.Bias1_Bias_n
	  section.data(71).logicalSrcIdx = 106;
	  section.data(71).dtTransOffset = 70;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_n
	  section.data(72).logicalSrcIdx = 107;
	  section.data(72).dtTransOffset = 71;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_p
	  section.data(73).logicalSrcIdx = 108;
	  section.data(73).dtTransOffset = 72;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_gk
	  section.data(74).logicalSrcIdx = 109;
	  section.data(74).dtTransOffset = 73;
	
	  ;% load_arduino_v_15_loop_P.Bias_Bias_j
	  section.data(75).logicalSrcIdx = 110;
	  section.data(75).dtTransOffset = 74;
	
	  ;% load_arduino_v_15_loop_P.Bias1_Bias_g
	  section.data(76).logicalSrcIdx = 111;
	  section.data(76).dtTransOffset = 75;
	
	  ;% load_arduino_v_15_loop_P.Bias_Bias_f
	  section.data(77).logicalSrcIdx = 112;
	  section.data(77).dtTransOffset = 76;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_mn
	  section.data(78).logicalSrcIdx = 113;
	  section.data(78).dtTransOffset = 77;
	
	  ;% load_arduino_v_15_loop_P.Bias1_Bias_f
	  section.data(79).logicalSrcIdx = 114;
	  section.data(79).dtTransOffset = 78;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_nv
	  section.data(80).logicalSrcIdx = 115;
	  section.data(80).dtTransOffset = 79;
	
	  ;% load_arduino_v_15_loop_P.Bias_Bias_e
	  section.data(81).logicalSrcIdx = 116;
	  section.data(81).dtTransOffset = 80;
	
	  ;% load_arduino_v_15_loop_P.Bias1_Bias_j
	  section.data(82).logicalSrcIdx = 117;
	  section.data(82).dtTransOffset = 81;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_d
	  section.data(83).logicalSrcIdx = 118;
	  section.data(83).dtTransOffset = 82;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_d5
	  section.data(84).logicalSrcIdx = 119;
	  section.data(84).dtTransOffset = 83;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_b
	  section.data(85).logicalSrcIdx = 120;
	  section.data(85).dtTransOffset = 84;
	
	  ;% load_arduino_v_15_loop_P.Bias_Bias_jc
	  section.data(86).logicalSrcIdx = 121;
	  section.data(86).dtTransOffset = 85;
	
	  ;% load_arduino_v_15_loop_P.Bias1_Bias_gb
	  section.data(87).logicalSrcIdx = 122;
	  section.data(87).dtTransOffset = 86;
	
	  ;% load_arduino_v_15_loop_P._Y0_b
	  section.data(88).logicalSrcIdx = 123;
	  section.data(88).dtTransOffset = 87;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_c
	  section.data(89).logicalSrcIdx = 124;
	  section.data(89).dtTransOffset = 89;
	
	  ;% load_arduino_v_15_loop_P.Constant8_Value
	  section.data(90).logicalSrcIdx = 125;
	  section.data(90).dtTransOffset = 90;
	
	  ;% load_arduino_v_15_loop_P.TAS_AL_Y0
	  section.data(91).logicalSrcIdx = 126;
	  section.data(91).dtTransOffset = 91;
	
	  ;% load_arduino_v_15_loop_P.QUOTA_AL_Y0
	  section.data(92).logicalSrcIdx = 127;
	  section.data(92).dtTransOffset = 92;
	
	  ;% load_arduino_v_15_loop_P.RC_AL_Y0
	  section.data(93).logicalSrcIdx = 128;
	  section.data(93).dtTransOffset = 93;
	
	  ;% load_arduino_v_15_loop_P.ROTTA_AL_Y0
	  section.data(94).logicalSrcIdx = 129;
	  section.data(94).dtTransOffset = 94;
	
	  ;% load_arduino_v_15_loop_P.H_LAT_Y0
	  section.data(95).logicalSrcIdx = 130;
	  section.data(95).dtTransOffset = 95;
	
	  ;% load_arduino_v_15_loop_P.H_LONG_Y0
	  section.data(96).logicalSrcIdx = 131;
	  section.data(96).dtTransOffset = 96;
	
	  ;% load_arduino_v_15_loop_P.H_ALT_Y0
	  section.data(97).logicalSrcIdx = 132;
	  section.data(97).dtTransOffset = 97;
	
	  ;% load_arduino_v_15_loop_P.distancewaypointsvirtuale_Value
	  section.data(98).logicalSrcIdx = 133;
	  section.data(98).dtTransOffset = 98;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_es
	  section.data(99).logicalSrcIdx = 134;
	  section.data(99).dtTransOffset = 101;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_k
	  section.data(100).logicalSrcIdx = 135;
	  section.data(100).dtTransOffset = 102;
	
	  ;% load_arduino_v_15_loop_P.altwaypointvirtuale_Value
	  section.data(101).logicalSrcIdx = 136;
	  section.data(101).dtTransOffset = 103;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_f
	  section.data(102).logicalSrcIdx = 137;
	  section.data(102).dtTransOffset = 106;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_d
	  section.data(103).logicalSrcIdx = 138;
	  section.data(103).dtTransOffset = 107;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_p
	  section.data(104).logicalSrcIdx = 139;
	  section.data(104).dtTransOffset = 108;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_b2
	  section.data(105).logicalSrcIdx = 140;
	  section.data(105).dtTransOffset = 109;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain
	  section.data(106).logicalSrcIdx = 141;
	  section.data(106).dtTransOffset = 110;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_j
	  section.data(107).logicalSrcIdx = 142;
	  section.data(107).dtTransOffset = 111;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_nw
	  section.data(108).logicalSrcIdx = 143;
	  section.data(108).dtTransOffset = 112;
	
	  ;% load_arduino_v_15_loop_P.Constant4_Value_o
	  section.data(109).logicalSrcIdx = 144;
	  section.data(109).dtTransOffset = 113;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_j
	  section.data(110).logicalSrcIdx = 145;
	  section.data(110).dtTransOffset = 114;
	
	  ;% load_arduino_v_15_loop_P.f_Value
	  section.data(111).logicalSrcIdx = 146;
	  section.data(111).dtTransOffset = 115;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_j
	  section.data(112).logicalSrcIdx = 147;
	  section.data(112).dtTransOffset = 116;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_j
	  section.data(113).logicalSrcIdx = 148;
	  section.data(113).dtTransOffset = 117;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_h
	  section.data(114).logicalSrcIdx = 149;
	  section.data(114).dtTransOffset = 118;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_f
	  section.data(115).logicalSrcIdx = 150;
	  section.data(115).dtTransOffset = 119;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_o
	  section.data(116).logicalSrcIdx = 151;
	  section.data(116).dtTransOffset = 120;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_ov
	  section.data(117).logicalSrcIdx = 152;
	  section.data(117).dtTransOffset = 121;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_jp
	  section.data(118).logicalSrcIdx = 153;
	  section.data(118).dtTransOffset = 122;
	
	  ;% load_arduino_v_15_loop_P.Memory7_InitialCondition
	  section.data(119).logicalSrcIdx = 154;
	  section.data(119).dtTransOffset = 123;
	
	  ;% load_arduino_v_15_loop_P.Memory5_InitialCondition
	  section.data(120).logicalSrcIdx = 155;
	  section.data(120).dtTransOffset = 124;
	
	  ;% load_arduino_v_15_loop_P.Memory1_InitialCondition_f
	  section.data(121).logicalSrcIdx = 156;
	  section.data(121).dtTransOffset = 125;
	
	  ;% load_arduino_v_15_loop_P.Memory2_InitialCondition
	  section.data(122).logicalSrcIdx = 157;
	  section.data(122).dtTransOffset = 126;
	
	  ;% load_arduino_v_15_loop_P.Constant4_Value_j
	  section.data(123).logicalSrcIdx = 158;
	  section.data(123).dtTransOffset = 127;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_n3
	  section.data(124).logicalSrcIdx = 159;
	  section.data(124).dtTransOffset = 128;
	
	  ;% load_arduino_v_15_loop_P.Switch2_Threshold
	  section.data(125).logicalSrcIdx = 160;
	  section.data(125).dtTransOffset = 129;
	
	  ;% load_arduino_v_15_loop_P.RC_Y0
	  section.data(126).logicalSrcIdx = 161;
	  section.data(126).dtTransOffset = 130;
	
	  ;% load_arduino_v_15_loop_P.VELOCITA_Y0
	  section.data(127).logicalSrcIdx = 162;
	  section.data(127).dtTransOffset = 131;
	
	  ;% load_arduino_v_15_loop_P.Out3_Y0_j
	  section.data(128).logicalSrcIdx = 163;
	  section.data(128).dtTransOffset = 132;
	
	  ;% load_arduino_v_15_loop_P.Out4_Y0_m
	  section.data(129).logicalSrcIdx = 164;
	  section.data(129).dtTransOffset = 133;
	
	  ;% load_arduino_v_15_loop_P.Memory4_InitialCondition
	  section.data(130).logicalSrcIdx = 165;
	  section.data(130).dtTransOffset = 134;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_bu
	  section.data(131).logicalSrcIdx = 166;
	  section.data(131).dtTransOffset = 135;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_jz
	  section.data(132).logicalSrcIdx = 167;
	  section.data(132).dtTransOffset = 136;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_gj
	  section.data(133).logicalSrcIdx = 168;
	  section.data(133).dtTransOffset = 137;
	
	  ;% load_arduino_v_15_loop_P.Out1_Y0_i
	  section.data(134).logicalSrcIdx = 169;
	  section.data(134).dtTransOffset = 138;
	
	  ;% load_arduino_v_15_loop_P.Out2_Y0_c
	  section.data(135).logicalSrcIdx = 170;
	  section.data(135).dtTransOffset = 139;
	
	  ;% load_arduino_v_15_loop_P.Out3_Y0_d
	  section.data(136).logicalSrcIdx = 171;
	  section.data(136).dtTransOffset = 140;
	
	  ;% load_arduino_v_15_loop_P.Out4_Y0_c
	  section.data(137).logicalSrcIdx = 172;
	  section.data(137).dtTransOffset = 141;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_ji
	  section.data(138).logicalSrcIdx = 173;
	  section.data(138).dtTransOffset = 142;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_gf
	  section.data(139).logicalSrcIdx = 174;
	  section.data(139).dtTransOffset = 143;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_ov4
	  section.data(140).logicalSrcIdx = 175;
	  section.data(140).dtTransOffset = 144;
	
	  ;% load_arduino_v_15_loop_P.SerialReceive_Protocol
	  section.data(141).logicalSrcIdx = 176;
	  section.data(141).dtTransOffset = 145;
	
	  ;% load_arduino_v_15_loop_P.SerialTransmit_Protocol_b
	  section.data(142).logicalSrcIdx = 177;
	  section.data(142).dtTransOffset = 146;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_o
	  section.data(143).logicalSrcIdx = 178;
	  section.data(143).dtTransOffset = 147;
	
	  ;% load_arduino_v_15_loop_P.Constant5_Value_n
	  section.data(144).logicalSrcIdx = 179;
	  section.data(144).dtTransOffset = 148;
	
	  ;% load_arduino_v_15_loop_P.Constant6_Value
	  section.data(145).logicalSrcIdx = 180;
	  section.data(145).dtTransOffset = 149;
	
	  ;% load_arduino_v_15_loop_P.Constant4_Value_l
	  section.data(146).logicalSrcIdx = 181;
	  section.data(146).dtTransOffset = 150;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_a
	  section.data(147).logicalSrcIdx = 182;
	  section.data(147).dtTransOffset = 151;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_c0
	  section.data(148).logicalSrcIdx = 183;
	  section.data(148).dtTransOffset = 152;
	
	  ;% load_arduino_v_15_loop_P.SerialReceive1_Protocol
	  section.data(149).logicalSrcIdx = 184;
	  section.data(149).dtTransOffset = 153;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_d
	  section.data(150).logicalSrcIdx = 185;
	  section.data(150).dtTransOffset = 154;
	
	  ;% load_arduino_v_15_loop_P.h_to_subtract_Y0
	  section.data(151).logicalSrcIdx = 186;
	  section.data(151).dtTransOffset = 155;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_l
	  section.data(152).logicalSrcIdx = 187;
	  section.data(152).dtTransOffset = 156;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_b
	  section.data(153).logicalSrcIdx = 188;
	  section.data(153).dtTransOffset = 157;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_ct
	  section.data(154).logicalSrcIdx = 189;
	  section.data(154).dtTransOffset = 158;
	
	  ;% load_arduino_v_15_loop_P.Outport_Y0
	  section.data(155).logicalSrcIdx = 190;
	  section.data(155).dtTransOffset = 159;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_ab
	  section.data(156).logicalSrcIdx = 191;
	  section.data(156).dtTransOffset = 160;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_b
	  section.data(157).logicalSrcIdx = 192;
	  section.data(157).dtTransOffset = 161;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_js
	  section.data(158).logicalSrcIdx = 193;
	  section.data(158).dtTransOffset = 162;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_hx
	  section.data(159).logicalSrcIdx = 194;
	  section.data(159).dtTransOffset = 163;
	
	  ;% load_arduino_v_15_loop_P.RateTransition_InitialCondition
	  section.data(160).logicalSrcIdx = 195;
	  section.data(160).dtTransOffset = 164;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_jg
	  section.data(161).logicalSrcIdx = 196;
	  section.data(161).dtTransOffset = 165;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_o
	  section.data(162).logicalSrcIdx = 197;
	  section.data(162).dtTransOffset = 166;
	
	  ;% load_arduino_v_15_loop_P.Memory1_InitialCondition_p
	  section.data(163).logicalSrcIdx = 198;
	  section.data(163).dtTransOffset = 167;
	
	  ;% load_arduino_v_15_loop_P.Switch_Threshold_f
	  section.data(164).logicalSrcIdx = 199;
	  section.data(164).dtTransOffset = 168;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_m
	  section.data(165).logicalSrcIdx = 200;
	  section.data(165).dtTransOffset = 169;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_n
	  section.data(166).logicalSrcIdx = 201;
	  section.data(166).dtTransOffset = 170;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_au
	  section.data(167).logicalSrcIdx = 202;
	  section.data(167).dtTransOffset = 171;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_c
	  section.data(168).logicalSrcIdx = 203;
	  section.data(168).dtTransOffset = 172;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_jp
	  section.data(169).logicalSrcIdx = 204;
	  section.data(169).dtTransOffset = 173;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_by
	  section.data(170).logicalSrcIdx = 205;
	  section.data(170).dtTransOffset = 176;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_k
	  section.data(171).logicalSrcIdx = 206;
	  section.data(171).dtTransOffset = 177;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_p
	  section.data(172).logicalSrcIdx = 207;
	  section.data(172).dtTransOffset = 178;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_p
	  section.data(173).logicalSrcIdx = 208;
	  section.data(173).dtTransOffset = 179;
	
	  ;% load_arduino_v_15_loop_P.UnitDelay_InitialCondition
	  section.data(174).logicalSrcIdx = 209;
	  section.data(174).dtTransOffset = 180;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_k
	  section.data(175).logicalSrcIdx = 210;
	  section.data(175).dtTransOffset = 181;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_mz
	  section.data(176).logicalSrcIdx = 211;
	  section.data(176).dtTransOffset = 182;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_kl
	  section.data(177).logicalSrcIdx = 212;
	  section.data(177).dtTransOffset = 183;
	
	  ;% load_arduino_v_15_loop_P.Gain2_Gain
	  section.data(178).logicalSrcIdx = 213;
	  section.data(178).dtTransOffset = 184;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_e
	  section.data(179).logicalSrcIdx = 214;
	  section.data(179).dtTransOffset = 185;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_hxg
	  section.data(180).logicalSrcIdx = 215;
	  section.data(180).dtTransOffset = 186;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_f
	  section.data(181).logicalSrcIdx = 216;
	  section.data(181).dtTransOffset = 187;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_e
	  section.data(182).logicalSrcIdx = 217;
	  section.data(182).dtTransOffset = 188;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_dn
	  section.data(183).logicalSrcIdx = 218;
	  section.data(183).dtTransOffset = 189;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_kf
	  section.data(184).logicalSrcIdx = 219;
	  section.data(184).dtTransOffset = 190;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_c
	  section.data(185).logicalSrcIdx = 220;
	  section.data(185).dtTransOffset = 191;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_d
	  section.data(186).logicalSrcIdx = 221;
	  section.data(186).dtTransOffset = 192;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_f2
	  section.data(187).logicalSrcIdx = 222;
	  section.data(187).dtTransOffset = 193;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_n
	  section.data(188).logicalSrcIdx = 223;
	  section.data(188).dtTransOffset = 194;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_ds
	  section.data(189).logicalSrcIdx = 224;
	  section.data(189).dtTransOffset = 195;
	
	  ;% load_arduino_v_15_loop_P.alt_r_Value
	  section.data(190).logicalSrcIdx = 225;
	  section.data(190).dtTransOffset = 196;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_bx
	  section.data(191).logicalSrcIdx = 226;
	  section.data(191).dtTransOffset = 197;
	
	  ;% load_arduino_v_15_loop_P.Gain4_Gain
	  section.data(192).logicalSrcIdx = 227;
	  section.data(192).dtTransOffset = 201;
	
	  ;% load_arduino_v_15_loop_P.vely_Value
	  section.data(193).logicalSrcIdx = 228;
	  section.data(193).dtTransOffset = 202;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_e
	  section.data(194).logicalSrcIdx = 229;
	  section.data(194).dtTransOffset = 203;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_b
	  section.data(195).logicalSrcIdx = 230;
	  section.data(195).dtTransOffset = 204;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_n1
	  section.data(196).logicalSrcIdx = 231;
	  section.data(196).dtTransOffset = 205;
	
	  ;% load_arduino_v_15_loop_P.Gain2_Gain_k
	  section.data(197).logicalSrcIdx = 232;
	  section.data(197).dtTransOffset = 206;
	
	  ;% load_arduino_v_15_loop_P.airspeedgroundspeedaltclimb1_Va
	  section.data(198).logicalSrcIdx = 233;
	  section.data(198).dtTransOffset = 207;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_l
	  section.data(199).logicalSrcIdx = 234;
	  section.data(199).dtTransOffset = 208;
	
	  ;% load_arduino_v_15_loop_P.Switch2_Threshold_a
	  section.data(200).logicalSrcIdx = 235;
	  section.data(200).dtTransOffset = 209;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_c
	  section.data(201).logicalSrcIdx = 236;
	  section.data(201).dtTransOffset = 210;
	
	  ;% load_arduino_v_15_loop_P.USCITAPERCENTUALE_Gain
	  section.data(202).logicalSrcIdx = 237;
	  section.data(202).dtTransOffset = 211;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_bh
	  section.data(203).logicalSrcIdx = 238;
	  section.data(203).dtTransOffset = 212;
	
	  ;% load_arduino_v_15_loop_P.Gain2_Gain_j
	  section.data(204).logicalSrcIdx = 239;
	  section.data(204).dtTransOffset = 213;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_i4
	  section.data(205).logicalSrcIdx = 240;
	  section.data(205).dtTransOffset = 214;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_fj
	  section.data(206).logicalSrcIdx = 241;
	  section.data(206).dtTransOffset = 215;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_h
	  section.data(207).logicalSrcIdx = 242;
	  section.data(207).dtTransOffset = 216;
	
	  ;% load_arduino_v_15_loop_P.Integrator_gainval
	  section.data(208).logicalSrcIdx = 243;
	  section.data(208).dtTransOffset = 217;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_jm
	  section.data(209).logicalSrcIdx = 244;
	  section.data(209).dtTransOffset = 218;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_od
	  section.data(210).logicalSrcIdx = 245;
	  section.data(210).dtTransOffset = 219;
	
	  ;% load_arduino_v_15_loop_P.Constant2_Value_m
	  section.data(211).logicalSrcIdx = 246;
	  section.data(211).dtTransOffset = 220;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_ng
	  section.data(212).logicalSrcIdx = 247;
	  section.data(212).dtTransOffset = 221;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_a
	  section.data(213).logicalSrcIdx = 248;
	  section.data(213).dtTransOffset = 222;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_cr
	  section.data(214).logicalSrcIdx = 249;
	  section.data(214).dtTransOffset = 223;
	
	  ;% load_arduino_v_15_loop_P.Integrator_gainval_g
	  section.data(215).logicalSrcIdx = 250;
	  section.data(215).dtTransOffset = 224;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_i
	  section.data(216).logicalSrcIdx = 251;
	  section.data(216).dtTransOffset = 225;
	
	  ;% load_arduino_v_15_loop_P.DiscreteWashoutFilter_NumCoef
	  section.data(217).logicalSrcIdx = 252;
	  section.data(217).dtTransOffset = 226;
	
	  ;% load_arduino_v_15_loop_P.DiscreteWashoutFilter_DenCoef
	  section.data(218).logicalSrcIdx = 253;
	  section.data(218).dtTransOffset = 228;
	
	  ;% load_arduino_v_15_loop_P.DiscreteWashoutFilter_InitialSt
	  section.data(219).logicalSrcIdx = 254;
	  section.data(219).dtTransOffset = 230;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_bh
	  section.data(220).logicalSrcIdx = 255;
	  section.data(220).dtTransOffset = 231;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_pa
	  section.data(221).logicalSrcIdx = 256;
	  section.data(221).dtTransOffset = 232;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_jr
	  section.data(222).logicalSrcIdx = 257;
	  section.data(222).dtTransOffset = 235;
	
	  ;% load_arduino_v_15_loop_P.Saturation_UpperSat
	  section.data(223).logicalSrcIdx = 258;
	  section.data(223).dtTransOffset = 236;
	
	  ;% load_arduino_v_15_loop_P.Saturation_LowerSat
	  section.data(224).logicalSrcIdx = 259;
	  section.data(224).dtTransOffset = 237;
	
	  ;% load_arduino_v_15_loop_P.DelayInput2_InitialCondition
	  section.data(225).logicalSrcIdx = 260;
	  section.data(225).dtTransOffset = 238;
	
	  ;% load_arduino_v_15_loop_P.sampletime_WtEt
	  section.data(226).logicalSrcIdx = 261;
	  section.data(226).dtTransOffset = 239;
	
	  ;% load_arduino_v_15_loop_P.PatohPa_Gain
	  section.data(227).logicalSrcIdx = 262;
	  section.data(227).dtTransOffset = 240;
	
	  ;% load_arduino_v_15_loop_P.Gain7_Gain
	  section.data(228).logicalSrcIdx = 263;
	  section.data(228).dtTransOffset = 241;
	
	  ;% load_arduino_v_15_loop_P.PatohPa1_Gain
	  section.data(229).logicalSrcIdx = 264;
	  section.data(229).dtTransOffset = 242;
	
	  ;% load_arduino_v_15_loop_P.RC_default_Value
	  section.data(230).logicalSrcIdx = 265;
	  section.data(230).dtTransOffset = 243;
	
	  ;% load_arduino_v_15_loop_P.Constant_Value_g
	  section.data(231).logicalSrcIdx = 266;
	  section.data(231).dtTransOffset = 244;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_jf
	  section.data(232).logicalSrcIdx = 267;
	  section.data(232).dtTransOffset = 245;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_n
	  section.data(233).logicalSrcIdx = 268;
	  section.data(233).dtTransOffset = 246;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_db
	  section.data(234).logicalSrcIdx = 269;
	  section.data(234).dtTransOffset = 247;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_dc
	  section.data(235).logicalSrcIdx = 270;
	  section.data(235).dtTransOffset = 248;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_bk
	  section.data(236).logicalSrcIdx = 271;
	  section.data(236).dtTransOffset = 249;
	
	  ;% load_arduino_v_15_loop_P.Gain2_Gain_m
	  section.data(237).logicalSrcIdx = 272;
	  section.data(237).dtTransOffset = 250;
	
	  ;% load_arduino_v_15_loop_P.HitCrossing_Offset
	  section.data(238).logicalSrcIdx = 273;
	  section.data(238).dtTransOffset = 251;
	
	  ;% load_arduino_v_15_loop_P.Gain_Gain_je
	  section.data(239).logicalSrcIdx = 274;
	  section.data(239).dtTransOffset = 252;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator_Amp
	  section.data(240).logicalSrcIdx = 275;
	  section.data(240).dtTransOffset = 253;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator_Period
	  section.data(241).logicalSrcIdx = 276;
	  section.data(241).dtTransOffset = 254;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator_Duty
	  section.data(242).logicalSrcIdx = 277;
	  section.data(242).dtTransOffset = 255;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator_PhaseDelay
	  section.data(243).logicalSrcIdx = 278;
	  section.data(243).dtTransOffset = 256;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator1_Amp
	  section.data(244).logicalSrcIdx = 279;
	  section.data(244).dtTransOffset = 257;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator1_Period
	  section.data(245).logicalSrcIdx = 280;
	  section.data(245).dtTransOffset = 258;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator1_Duty
	  section.data(246).logicalSrcIdx = 281;
	  section.data(246).dtTransOffset = 259;
	
	  ;% load_arduino_v_15_loop_P.PulseGenerator1_PhaseDelay
	  section.data(247).logicalSrcIdx = 282;
	  section.data(247).dtTransOffset = 260;
	
	  ;% load_arduino_v_15_loop_P.Constant4_Value_a
	  section.data(248).logicalSrcIdx = 283;
	  section.data(248).dtTransOffset = 261;
	
	  ;% load_arduino_v_15_loop_P.Constant5_Value_a
	  section.data(249).logicalSrcIdx = 284;
	  section.data(249).dtTransOffset = 262;
	
	  ;% load_arduino_v_15_loop_P.Memory2_InitialCondition_o
	  section.data(250).logicalSrcIdx = 285;
	  section.data(250).dtTransOffset = 263;
	
	  ;% load_arduino_v_15_loop_P.Switch1_Threshold_c
	  section.data(251).logicalSrcIdx = 286;
	  section.data(251).dtTransOffset = 264;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Constant_Value_gw
	  section.data(1).logicalSrcIdx = 287;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Out2_Y0_cb
	  section.data(1).logicalSrcIdx = 288;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.T_Y0
	  section.data(2).logicalSrcIdx = 289;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.T_0_Y0
	  section.data(3).logicalSrcIdx = 290;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.Switch_Threshold_p
	  section.data(4).logicalSrcIdx = 291;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.Gain3_Gain
	  section.data(5).logicalSrcIdx = 292;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.p_Y0
	  section.data(1).logicalSrcIdx = 293;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.Constant7_Value
	  section.data(2).logicalSrcIdx = 294;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.Constant10_Value
	  section.data(3).logicalSrcIdx = 295;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.Constant11_Value
	  section.data(4).logicalSrcIdx = 296;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.Constant8_Value_e
	  section.data(5).logicalSrcIdx = 297;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_P.Constant9_Value
	  section.data(6).logicalSrcIdx = 298;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_P.onboard_control_sensor_presentu
	  section.data(7).logicalSrcIdx = 299;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Out3_Y0_a
	  section.data(1).logicalSrcIdx = 300;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.Switch_Threshold_m
	  section.data(2).logicalSrcIdx = 301;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.Gain1_Gain_eu
	  section.data(3).logicalSrcIdx = 302;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Out4_Y0_i
	  section.data(1).logicalSrcIdx = 303;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_at
	  section.data(2).logicalSrcIdx = 304;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.loaduint16_Value
	  section.data(3).logicalSrcIdx = 305;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P._Value
	  section.data(4).logicalSrcIdx = 306;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_g
	  section.data(5).logicalSrcIdx = 307;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.UnitDelay_InitialCondition_l
	  section.data(1).logicalSrcIdx = 308;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.Constant3_Value_ok
	  section.data(2).logicalSrcIdx = 309;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Gain3_Gain_o
	  section.data(1).logicalSrcIdx = 310;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_j
	  section.data(1).logicalSrcIdx = 311;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.Memory1_InitialCondition_g
	  section.data(2).logicalSrcIdx = 312;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.Memory2_InitialCondition_n
	  section.data(3).logicalSrcIdx = 313;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.Memory6_InitialCondition
	  section.data(4).logicalSrcIdx = 314;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.mario_Y0
	  section.data(5).logicalSrcIdx = 315;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_P.Memory4_InitialCondition_g
	  section.data(6).logicalSrcIdx = 316;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_P.Delay_InitialCondition
	  section.data(7).logicalSrcIdx = 317;
	  section.data(7).dtTransOffset = 305;
	
	  ;% load_arduino_v_15_loop_P.Constant1_Value_a
	  section.data(8).logicalSrcIdx = 318;
	  section.data(8).dtTransOffset = 306;
	
	  ;% load_arduino_v_15_loop_P.SIUAVuint8_Value
	  section.data(9).logicalSrcIdx = 319;
	  section.data(9).dtTransOffset = 307;
	
	  ;% load_arduino_v_15_loop_P.Memory5_InitialCondition_d
	  section.data(10).logicalSrcIdx = 320;
	  section.data(10).dtTransOffset = 308;
	
	  ;% load_arduino_v_15_loop_P.Memory1_InitialCondition_b
	  section.data(11).logicalSrcIdx = 321;
	  section.data(11).dtTransOffset = 309;
	
	  ;% load_arduino_v_15_loop_P.Memory_InitialCondition_o
	  section.data(12).logicalSrcIdx = 322;
	  section.data(12).dtTransOffset = 310;
	
	  ;% load_arduino_v_15_loop_P.Memory3_InitialCondition_c
	  section.data(13).logicalSrcIdx = 323;
	  section.data(13).dtTransOffset = 311;
	
	  ;% load_arduino_v_15_loop_P.Memory2_InitialCondition_g
	  section.data(14).logicalSrcIdx = 324;
	  section.data(14).dtTransOffset = 312;
	
	  ;% load_arduino_v_15_loop_P.Typefixed_wingAutopilotgeneric_
	  section.data(15).logicalSrcIdx = 325;
	  section.data(15).dtTransOffset = 321;
	
	  ;% load_arduino_v_15_loop_P.InizioMSG_Value
	  section.data(16).logicalSrcIdx = 326;
	  section.data(16).dtTransOffset = 323;
	
	  ;% load_arduino_v_15_loop_P.FineMSG1_Value
	  section.data(17).logicalSrcIdx = 327;
	  section.data(17).dtTransOffset = 325;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.One_time_initialization.BitwiseOperator1_BitMask
	  section.data(1).logicalSrcIdx = 328;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.One_time_initialization.I2CRead12_SampleTime
	  section.data(1).logicalSrcIdx = 329;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_T2_Y0
	  section.data(1).logicalSrcIdx = 330;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_T3_Y0
	  section.data(2).logicalSrcIdx = 331;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p2_Y0
	  section.data(3).logicalSrcIdx = 332;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p3_Y0
	  section.data(4).logicalSrcIdx = 333;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p4_Y0
	  section.data(5).logicalSrcIdx = 334;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p5_Y0
	  section.data(6).logicalSrcIdx = 335;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p6_Y0
	  section.data(7).logicalSrcIdx = 336;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p7_Y0
	  section.data(8).logicalSrcIdx = 337;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p8_Y0
	  section.data(9).logicalSrcIdx = 338;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p9_Y0
	  section.data(10).logicalSrcIdx = 339;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_T1_Y0
	  section.data(1).logicalSrcIdx = 340;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.dig_p1_Y0
	  section.data(2).logicalSrcIdx = 341;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.pwm_max_min_Y0
	  section.data(3).logicalSrcIdx = 342;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.registromemoria2_Value
	  section.data(4).logicalSrcIdx = 343;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.One_time_initialization.Constant1_Value
	  section.data(1).logicalSrcIdx = 344;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_P.One_time_initialization.Constant4_Value
	  section.data(2).logicalSrcIdx = 345;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.ResettableSubsystem_o.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 346;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_P.ResettableSubsystem.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 347;
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
    nTotSects     = 20;
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
    ;% Auto data (load_arduino_v_15_loop_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.ComplextoRealImag
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.Memory
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.SFunction_o9
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o11
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_B.TmpSignalConversionAtSFunctionI
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_B.WP_info
	  section.data(4).logicalSrcIdx = 109;
	  section.data(4).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 49;
      section.data(49)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.Product1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.Constant2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion5
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_B.Gain4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_B.Go_Home
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_B.Abs
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_B.Switch
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_B.h_goHome
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_B.QUOTA
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_B.Gain
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_B.Gain_g
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_B.Px
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_loop_B.Abs1
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_B.Memory5
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_loop_B.Memory1
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_B.Memory2
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_B.QUOTA_m
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_loop_B.In
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_loop_B.Sum2
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_loop_B.maneuver_selector
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_loop_B.trig_approach
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_loop_B.trig_flare
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_B.approach_selector
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_loop_B.h_Home
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_loop_B.Multiply
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_loop_B.x_f_out
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_loop_B.h_f_out
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_loop_B.k_x_out
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 32;
	
	  ;% load_arduino_v_15_loop_B.h_c_out
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_loop_B.no_solution
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 34;
	
	  ;% load_arduino_v_15_loop_B.counter_out
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_loop_B.h_vett
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 36;
	
	  ;% load_arduino_v_15_loop_B.In_g
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 37;
	
	  ;% load_arduino_v_15_loop_B.In_k
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 38;
	
	  ;% load_arduino_v_15_loop_B.Fase_ATO
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 39;
	
	  ;% load_arduino_v_15_loop_B.eq_rot
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 40;
	
	  ;% load_arduino_v_15_loop_B.h_ref
	  section.data(37).logicalSrcIdx = 42;
	  section.data(37).dtTransOffset = 41;
	
	  ;% load_arduino_v_15_loop_B.psi_ref_selector
	  section.data(38).logicalSrcIdx = 45;
	  section.data(38).dtTransOffset = 42;
	
	  ;% load_arduino_v_15_loop_B.theta_ground_selector
	  section.data(39).logicalSrcIdx = 46;
	  section.data(39).dtTransOffset = 43;
	
	  ;% load_arduino_v_15_loop_B.Switch_n
	  section.data(40).logicalSrcIdx = 52;
	  section.data(40).dtTransOffset = 44;
	
	  ;% load_arduino_v_15_loop_B.Switch_AL
	  section.data(41).logicalSrcIdx = 53;
	  section.data(41).dtTransOffset = 45;
	
	  ;% load_arduino_v_15_loop_B.Switch_l
	  section.data(42).logicalSrcIdx = 54;
	  section.data(42).dtTransOffset = 46;
	
	  ;% load_arduino_v_15_loop_B.Switch_a
	  section.data(43).logicalSrcIdx = 55;
	  section.data(43).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_loop_B.switch_manetta
	  section.data(44).logicalSrcIdx = 56;
	  section.data(44).dtTransOffset = 48;
	
	  ;% load_arduino_v_15_loop_B.switch_equilibratore
	  section.data(45).logicalSrcIdx = 57;
	  section.data(45).dtTransOffset = 49;
	
	  ;% load_arduino_v_15_loop_B.switch_alettoni
	  section.data(46).logicalSrcIdx = 58;
	  section.data(46).dtTransOffset = 50;
	
	  ;% load_arduino_v_15_loop_B.switch_timone
	  section.data(47).logicalSrcIdx = 59;
	  section.data(47).dtTransOffset = 51;
	
	  ;% load_arduino_v_15_loop_B.modo
	  section.data(48).logicalSrcIdx = 63;
	  section.data(48).dtTransOffset = 52;
	
	  ;% load_arduino_v_15_loop_B.test
	  section.data(49).logicalSrcIdx = 66;
	  section.data(49).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o3
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder_o1_n
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.Switch1
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion1
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.AGAC
	  section.data(3).logicalSrcIdx = 80;
	  section.data(3).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion2
	  section.data(4).logicalSrcIdx = 81;
	  section.data(4).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion_l
	  section.data(5).logicalSrcIdx = 82;
	  section.data(5).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion1_g
	  section.data(6).logicalSrcIdx = 83;
	  section.data(6).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion4
	  section.data(7).logicalSrcIdx = 84;
	  section.data(7).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_B.T
	  section.data(8).logicalSrcIdx = 85;
	  section.data(8).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder_o1
	  section.data(9).logicalSrcIdx = 86;
	  section.data(9).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o2_e
	  section.data(10).logicalSrcIdx = 87;
	  section.data(10).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_loop_B.WP_param
	  section.data(11).logicalSrcIdx = 88;
	  section.data(11).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_loop_B.Val_out_MAV
	  section.data(12).logicalSrcIdx = 89;
	  section.data(12).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder_o2
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.Add
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion_a
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion1_i
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion_ay
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder_o2_a
	  section.data(6).logicalSrcIdx = 95;
	  section.data(6).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.SFunction_o2
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion3
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion8
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder1
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o2
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.ByteReversal
	  section.data(2).logicalSrcIdx = 73;
	  section.data(2).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o8
	  section.data(3).logicalSrcIdx = 74;
	  section.data(3).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o10
	  section.data(4).logicalSrcIdx = 75;
	  section.data(4).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o13
	  section.data(5).logicalSrcIdx = 76;
	  section.data(5).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o17
	  section.data(6).logicalSrcIdx = 77;
	  section.data(6).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.SFunction_o7
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o1
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.DataTypeConversion2_h
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.Throttle
	  section.data(2).logicalSrcIdx = 102;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.Heading
	  section.data(3).logicalSrcIdx = 103;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_B.Memory_a
	  section.data(4).logicalSrcIdx = 104;
	  section.data(4).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o3
	  section.data(5).logicalSrcIdx = 105;
	  section.data(5).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o4
	  section.data(6).logicalSrcIdx = 106;
	  section.data(6).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion1_h
	  section.data(7).logicalSrcIdx = 107;
	  section.data(7).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o4
	  section.data(8).logicalSrcIdx = 108;
	  section.data(8).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_loop_B.new_mex
	  section.data(9).logicalSrcIdx = 110;
	  section.data(9).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_B.GC_info
	  section.data(10).logicalSrcIdx = 111;
	  section.data(10).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.Gain1
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion_ld
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion1_p
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_B.Heading_g
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_B.PWM_throttle
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder2
	  section.data(6).logicalSrcIdx = 117;
	  section.data(6).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_loop_B.PWM_elevator
	  section.data(7).logicalSrcIdx = 118;
	  section.data(7).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_B.PWM_aileron
	  section.data(8).logicalSrcIdx = 119;
	  section.data(8).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_loop_B.PWM_rudder
	  section.data(9).logicalSrcIdx = 120;
	  section.data(9).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion2_m
	  section.data(10).logicalSrcIdx = 121;
	  section.data(10).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion_lx
	  section.data(11).logicalSrcIdx = 122;
	  section.data(11).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion_p
	  section.data(12).logicalSrcIdx = 123;
	  section.data(12).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion1_c
	  section.data(13).logicalSrcIdx = 124;
	  section.data(13).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_loop_B.DataTypeConversion2_j
	  section.data(14).logicalSrcIdx = 125;
	  section.data(14).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_loop_B.Sum
	  section.data(15).logicalSrcIdx = 126;
	  section.data(15).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder_o2_f
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o3_p
	  section.data(2).logicalSrcIdx = 131;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.SFunctionBuilder_o1_h
	  section.data(3).logicalSrcIdx = 132;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_B.Memory1_p
	  section.data(4).logicalSrcIdx = 133;
	  section.data(4).dtTransOffset = 102;
	
	  ;% load_arduino_v_15_loop_B.Memory_k
	  section.data(5).logicalSrcIdx = 134;
	  section.data(5).dtTransOffset = 104;
	
	  ;% load_arduino_v_15_loop_B.Memory3
	  section.data(6).logicalSrcIdx = 135;
	  section.data(6).dtTransOffset = 108;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o1
	  section.data(7).logicalSrcIdx = 136;
	  section.data(7).dtTransOffset = 109;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o3_j
	  section.data(8).logicalSrcIdx = 137;
	  section.data(8).dtTransOffset = 113;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o4_n
	  section.data(9).logicalSrcIdx = 138;
	  section.data(9).dtTransOffset = 114;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o5
	  section.data(10).logicalSrcIdx = 139;
	  section.data(10).dtTransOffset = 116;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o6
	  section.data(11).logicalSrcIdx = 140;
	  section.data(11).dtTransOffset = 119;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o12
	  section.data(12).logicalSrcIdx = 141;
	  section.data(12).dtTransOffset = 120;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o14
	  section.data(13).logicalSrcIdx = 142;
	  section.data(13).dtTransOffset = 121;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o15
	  section.data(14).logicalSrcIdx = 143;
	  section.data(14).dtTransOffset = 122;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o16
	  section.data(15).logicalSrcIdx = 144;
	  section.data(15).dtTransOffset = 123;
	
	  ;% load_arduino_v_15_loop_B.TmpSignalConversionAtSFunctio_m
	  section.data(16).logicalSrcIdx = 145;
	  section.data(16).dtTransOffset = 124;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o1_j
	  section.data(17).logicalSrcIdx = 146;
	  section.data(17).dtTransOffset = 128;
	
	  ;% load_arduino_v_15_loop_B.SFunction_o2_f
	  section.data(18).logicalSrcIdx = 147;
	  section.data(18).dtTransOffset = 129;
	
	  ;% load_arduino_v_15_loop_B.TmpSignalConversionAtBytePackIn
	  section.data(19).logicalSrcIdx = 148;
	  section.data(19).dtTransOffset = 393;
	
	  ;% load_arduino_v_15_loop_B.BytePack
	  section.data(20).logicalSrcIdx = 149;
	  section.data(20).dtTransOffset = 395;
	
	  ;% load_arduino_v_15_loop_B.Mex_out
	  section.data(21).logicalSrcIdx = 150;
	  section.data(21).dtTransOffset = 458;
	
	  ;% load_arduino_v_15_loop_B.indice_dimario
	  section.data(22).logicalSrcIdx = 151;
	  section.data(22).dtTransOffset = 499;
	
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o1_o
	  section.data(23).logicalSrcIdx = 152;
	  section.data(23).dtTransOffset = 500;
	
	  ;% load_arduino_v_15_loop_B.ByteUnpack_o5
	  section.data(24).logicalSrcIdx = 153;
	  section.data(24).dtTransOffset = 502;
	
	  ;% load_arduino_v_15_loop_B.messaggio
	  section.data(25).logicalSrcIdx = 154;
	  section.data(25).dtTransOffset = 503;
	
	  ;% load_arduino_v_15_loop_B.iflogic
	  section.data(26).logicalSrcIdx = 155;
	  section.data(26).dtTransOffset = 534;
	
	  ;% load_arduino_v_15_loop_B.mess_out
	  section.data(27).logicalSrcIdx = 157;
	  section.data(27).dtTransOffset = 535;
	
	  ;% load_arduino_v_15_loop_B.AP_int
	  section.data(28).logicalSrcIdx = 158;
	  section.data(28).dtTransOffset = 635;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.B_Remaining
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.Ap_sel
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.HitCrossing
	  section.data(2).logicalSrcIdx = 161;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.One_time_initialization.ByteUnpack
	  section.data(1).logicalSrcIdx = 162;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead3
	  section.data(2).logicalSrcIdx = 163;
	  section.data(2).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead
	  section.data(3).logicalSrcIdx = 164;
	  section.data(3).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead9
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead8
	  section.data(2).logicalSrcIdx = 166;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead7
	  section.data(3).logicalSrcIdx = 167;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead6
	  section.data(4).logicalSrcIdx = 168;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead5
	  section.data(5).logicalSrcIdx = 169;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead4
	  section.data(6).logicalSrcIdx = 170;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead2
	  section.data(7).logicalSrcIdx = 171;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead11
	  section.data(8).logicalSrcIdx = 172;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead10
	  section.data(9).logicalSrcIdx = 173;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead1
	  section.data(10).logicalSrcIdx = 174;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_B.One_time_initialization.I2CRead12
	  section.data(1).logicalSrcIdx = 175;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
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
    nTotSects     = 21;
    sectIdxOffset = 20;
    
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
    ;% Auto data (load_arduino_v_15_loop_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.obj_o
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.obj_e
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.obj_m
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.obj_f
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.obj_p
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.obj_b
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.obj_d
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder_DSTATE
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder_DSTATE_l
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_DW.UnitDelay_DSTATE
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_DW.Integrator_DSTATE
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_DW.Integrator_DSTATE_p
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_DW.DiscreteWashoutFilter_states
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_DW.DelayInput2_DSTATE
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder10_DSTATE
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder4_DSTATE
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder5_DSTATE
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder9_DSTATE
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_DW.SFunctionBuilder_DSTATE_n
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_DW.RateTransition_Buffer0
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_DW.Memory1_PreviousInput
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_loop_DW.Memory2_PreviousInput
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput_l
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_loop_DW.P_ref
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_DW.rl_up
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 27;
	
	  ;% load_arduino_v_15_loop_DW.rl_dw
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 28;
	
	  ;% load_arduino_v_15_loop_DW.flag
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 29;
	
	  ;% load_arduino_v_15_loop_DW.Memory4_PreviousInput
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 30;
	
	  ;% load_arduino_v_15_loop_DW.flag_m
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 31;
	
	  ;% load_arduino_v_15_loop_DW.lat1
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 32;
	
	  ;% load_arduino_v_15_loop_DW.long1
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 33;
	
	  ;% load_arduino_v_15_loop_DW.Memory7_PreviousInput
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 34;
	
	  ;% load_arduino_v_15_loop_DW.Memory5_PreviousInput
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 35;
	
	  ;% load_arduino_v_15_loop_DW.Memory1_PreviousInput_l
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 36;
	
	  ;% load_arduino_v_15_loop_DW.Memory2_PreviousInput_f
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 37;
	
	  ;% load_arduino_v_15_loop_DW.x
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 38;
	
	  ;% load_arduino_v_15_loop_DW.cycle_count
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 42;
	
	  ;% load_arduino_v_15_loop_DW.eps
	  section.data(33).logicalSrcIdx = 41;
	  section.data(33).dtTransOffset = 43;
	
	  ;% load_arduino_v_15_loop_DW.flag_c
	  section.data(34).logicalSrcIdx = 42;
	  section.data(34).dtTransOffset = 47;
	
	  ;% load_arduino_v_15_loop_DW.Memory3_PreviousInput
	  section.data(35).logicalSrcIdx = 43;
	  section.data(35).dtTransOffset = 48;
	
	  ;% load_arduino_v_15_loop_DW.ALT_ref
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 49;
	
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput_i
	  section.data(37).logicalSrcIdx = 47;
	  section.data(37).dtTransOffset = 50;
	
	  ;% load_arduino_v_15_loop_DW.Memory1_PreviousInput_o
	  section.data(38).logicalSrcIdx = 48;
	  section.data(38).dtTransOffset = 51;
	
	  ;% load_arduino_v_15_loop_DW.alarm
	  section.data(39).logicalSrcIdx = 49;
	  section.data(39).dtTransOffset = 52;
	
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput_h
	  section.data(40).logicalSrcIdx = 50;
	  section.data(40).dtTransOffset = 53;
	
	  ;% load_arduino_v_15_loop_DW.mess_len
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 54;
	
	  ;% load_arduino_v_15_loop_DW.test1
	  section.data(42).logicalSrcIdx = 53;
	  section.data(42).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.riferimenti
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.WP_dbP
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_DW.WP_dbP_AL
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.clockTickCounter_c
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.is_c10_load_arduino_v_15_loop
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.is_c1_load_arduino_v_15_loop
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_DW.is_c21_load_arduino_v_15_loop
	  section.data(3).logicalSrcIdx = 68;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_DW.is_c26_load_arduino_v_15_loop
	  section.data(4).logicalSrcIdx = 69;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_DW.is_AUTOMATICA
	  section.data(5).logicalSrcIdx = 70;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_DW.is_c23_load_arduino_v_15_loop
	  section.data(6).logicalSrcIdx = 71;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_DW.is_c9_load_arduino_v_15_loop
	  section.data(7).logicalSrcIdx = 72;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.HitCrossing_MODE
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput_ic
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput_n
	  section.data(2).logicalSrcIdx = 75;
	  section.data(2).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_DW.counter
	  section.data(3).logicalSrcIdx = 76;
	  section.data(3).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_DW.WP_dbI
	  section.data(4).logicalSrcIdx = 77;
	  section.data(4).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.UnitDelay_DSTATE_d
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.Integrator_PrevResetState
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem2_SubsysRanBC
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem1_SubsysRanBC
	  section.data(4).logicalSrcIdx = 83;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem1_SubsysRanBC_n
	  section.data(5).logicalSrcIdx = 84;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_DW.Execution_loop_SubsysRanBC
	  section.data(6).logicalSrcIdx = 85;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem1_SubsysRanBC_l
	  section.data(7).logicalSrcIdx = 86;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem2_SubsysRanBC_m
	  section.data(8).logicalSrcIdx = 87;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem3_SubsysRanBC
	  section.data(9).logicalSrcIdx = 88;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem2_SubsysRanBC_c
	  section.data(10).logicalSrcIdx = 89;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem1_SubsysRanBC_p
	  section.data(11).logicalSrcIdx = 90;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_DW.SampleandHold_SubsysRanBC
	  section.data(12).logicalSrcIdx = 91;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_DW.INSEGUIMENTOCENTROPISTA_SubsysR
	  section.data(13).logicalSrcIdx = 92;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_DW.FLARE_SubsysRanBC
	  section.data(14).logicalSrcIdx = 93;
	  section.data(14).dtTransOffset = 13;
	
	  ;% load_arduino_v_15_loop_DW.APPROACH_SubsysRanBC
	  section.data(15).logicalSrcIdx = 94;
	  section.data(15).dtTransOffset = 14;
	
	  ;% load_arduino_v_15_loop_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(16).logicalSrcIdx = 95;
	  section.data(16).dtTransOffset = 15;
	
	  ;% load_arduino_v_15_loop_DW.Subsystem_SubsysRanBC_h
	  section.data(17).logicalSrcIdx = 96;
	  section.data(17).dtTransOffset = 16;
	
	  ;% load_arduino_v_15_loop_DW.DECOLLOAUTOMATICO_SubsysRanBC
	  section.data(18).logicalSrcIdx = 97;
	  section.data(18).dtTransOffset = 17;
	
	  ;% load_arduino_v_15_loop_DW.SampleandHold1_SubsysRanBC
	  section.data(19).logicalSrcIdx = 98;
	  section.data(19).dtTransOffset = 18;
	
	  ;% load_arduino_v_15_loop_DW.SampleandHold_SubsysRanBC_h
	  section.data(20).logicalSrcIdx = 99;
	  section.data(20).dtTransOffset = 19;
	
	  ;% load_arduino_v_15_loop_DW.Enabled_SubsysRanBC
	  section.data(21).logicalSrcIdx = 100;
	  section.data(21).dtTransOffset = 20;
	
	  ;% load_arduino_v_15_loop_DW.Enabled_SubsysRanBC_p
	  section.data(22).logicalSrcIdx = 101;
	  section.data(22).dtTransOffset = 21;
	
	  ;% load_arduino_v_15_loop_DW.Enabled_SubsysRanBC_o
	  section.data(23).logicalSrcIdx = 102;
	  section.data(23).dtTransOffset = 22;
	
	  ;% load_arduino_v_15_loop_DW.EnabledSubsystem_SubsysRanBC
	  section.data(24).logicalSrcIdx = 103;
	  section.data(24).dtTransOffset = 23;
	
	  ;% load_arduino_v_15_loop_DW.EnabledSubsystem_SubsysRanBC_c
	  section.data(25).logicalSrcIdx = 104;
	  section.data(25).dtTransOffset = 24;
	
	  ;% load_arduino_v_15_loop_DW.EnabledSubsystem_SubsysRanBC_h
	  section.data(26).logicalSrcIdx = 105;
	  section.data(26).dtTransOffset = 25;
	
	  ;% load_arduino_v_15_loop_DW.Enable_SubsysRanBC
	  section.data(27).logicalSrcIdx = 106;
	  section.data(27).dtTransOffset = 26;
	
	  ;% load_arduino_v_15_loop_DW.sendbyte_SubsysRanBC
	  section.data(28).logicalSrcIdx = 107;
	  section.data(28).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.Memory4_PreviousInput_c
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.Memory5_PreviousInput_l
	  section.data(2).logicalSrcIdx = 109;
	  section.data(2).dtTransOffset = 300;
	
	  ;% load_arduino_v_15_loop_DW.Memory1_PreviousInput_d
	  section.data(3).logicalSrcIdx = 110;
	  section.data(3).dtTransOffset = 400;
	
	  ;% load_arduino_v_15_loop_DW.Memory_PreviousInput_h5
	  section.data(4).logicalSrcIdx = 111;
	  section.data(4).dtTransOffset = 402;
	
	  ;% load_arduino_v_15_loop_DW.Memory3_PreviousInput_o
	  section.data(5).logicalSrcIdx = 112;
	  section.data(5).dtTransOffset = 406;
	
	  ;% load_arduino_v_15_loop_DW.Memory2_PreviousInput_a
	  section.data(6).logicalSrcIdx = 113;
	  section.data(6).dtTransOffset = 407;
	
	  ;% load_arduino_v_15_loop_DW.message
	  section.data(7).logicalSrcIdx = 114;
	  section.data(7).dtTransOffset = 416;
	
	  ;% load_arduino_v_15_loop_DW.counter_k
	  section.data(8).logicalSrcIdx = 115;
	  section.data(8).dtTransOffset = 496;
	
	  ;% load_arduino_v_15_loop_DW.message_k
	  section.data(9).logicalSrcIdx = 116;
	  section.data(9).dtTransOffset = 497;
	
	  ;% load_arduino_v_15_loop_DW.counter_n
	  section.data(10).logicalSrcIdx = 117;
	  section.data(10).dtTransOffset = 528;
	
	  ;% load_arduino_v_15_loop_DW.is_active_c10_load_arduino_v_15
	  section.data(11).logicalSrcIdx = 118;
	  section.data(11).dtTransOffset = 529;
	
	  ;% load_arduino_v_15_loop_DW.Memory1_PreviousInput_h
	  section.data(12).logicalSrcIdx = 120;
	  section.data(12).dtTransOffset = 530;
	
	  ;% load_arduino_v_15_loop_DW.Memory6_PreviousInput
	  section.data(13).logicalSrcIdx = 122;
	  section.data(13).dtTransOffset = 531;
	
	  ;% load_arduino_v_15_loop_DW.is_active_c1_load_arduino_v_15_
	  section.data(14).logicalSrcIdx = 123;
	  section.data(14).dtTransOffset = 532;
	
	  ;% load_arduino_v_15_loop_DW.temporalCounter_i1
	  section.data(15).logicalSrcIdx = 124;
	  section.data(15).dtTransOffset = 533;
	
	  ;% load_arduino_v_15_loop_DW.is_active_c21_load_arduino_v_15
	  section.data(16).logicalSrcIdx = 125;
	  section.data(16).dtTransOffset = 534;
	
	  ;% load_arduino_v_15_loop_DW.is_active_c26_load_arduino_v_15
	  section.data(17).logicalSrcIdx = 126;
	  section.data(17).dtTransOffset = 535;
	
	  ;% load_arduino_v_15_loop_DW.is_active_c23_load_arduino_v_15
	  section.data(18).logicalSrcIdx = 127;
	  section.data(18).dtTransOffset = 536;
	
	  ;% load_arduino_v_15_loop_DW.is_active_c9_load_arduino_v_15_
	  section.data(19).logicalSrcIdx = 128;
	  section.data(19).dtTransOffset = 537;
	
	  ;% load_arduino_v_15_loop_DW.i
	  section.data(20).logicalSrcIdx = 129;
	  section.data(20).dtTransOffset = 538;
	
	  ;% load_arduino_v_15_loop_DW.message_i
	  section.data(21).logicalSrcIdx = 130;
	  section.data(21).dtTransOffset = 539;
	
	  ;% load_arduino_v_15_loop_DW.counter_a
	  section.data(22).logicalSrcIdx = 131;
	  section.data(22).dtTransOffset = 639;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.start_found
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.end_found
	  section.data(2).logicalSrcIdx = 133;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_DW.start_found_c
	  section.data(3).logicalSrcIdx = 137;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_DW.x_not_empty
	  section.data(4).logicalSrcIdx = 142;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_DW.x_new_not_empty
	  section.data(5).logicalSrcIdx = 143;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_DW.cycle_count_not_empty
	  section.data(6).logicalSrcIdx = 144;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_DW.eps_not_empty
	  section.data(7).logicalSrcIdx = 145;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_DW.Tf_not_empty
	  section.data(8).logicalSrcIdx = 146;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_DW.Interr_parz
	  section.data(9).logicalSrcIdx = 148;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_DW.WP_dbP_not_empty
	  section.data(10).logicalSrcIdx = 149;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_DW.WP_dbP_AL_not_empty
	  section.data(11).logicalSrcIdx = 150;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_DW.Enabled_MODE
	  section.data(12).logicalSrcIdx = 151;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_DW.Enabled_MODE_g
	  section.data(13).logicalSrcIdx = 152;
	  section.data(13).dtTransOffset = 12;
	
	  ;% load_arduino_v_15_loop_DW.Enabled_MODE_m
	  section.data(14).logicalSrcIdx = 153;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_i
	  section.data(2).logicalSrcIdx = 155;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_c
	  section.data(3).logicalSrcIdx = 156;
	  section.data(3).dtTransOffset = 2;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_b
	  section.data(4).logicalSrcIdx = 157;
	  section.data(4).dtTransOffset = 3;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_k
	  section.data(5).logicalSrcIdx = 158;
	  section.data(5).dtTransOffset = 4;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_co
	  section.data(6).logicalSrcIdx = 159;
	  section.data(6).dtTransOffset = 5;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_k4
	  section.data(7).logicalSrcIdx = 160;
	  section.data(7).dtTransOffset = 6;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_d
	  section.data(8).logicalSrcIdx = 161;
	  section.data(8).dtTransOffset = 7;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_ir
	  section.data(9).logicalSrcIdx = 162;
	  section.data(9).dtTransOffset = 8;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_l
	  section.data(10).logicalSrcIdx = 163;
	  section.data(10).dtTransOffset = 9;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_d0
	  section.data(11).logicalSrcIdx = 164;
	  section.data(11).dtTransOffset = 10;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_o
	  section.data(12).logicalSrcIdx = 165;
	  section.data(12).dtTransOffset = 11;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_kf
	  section.data(13).logicalSrcIdx = 166;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_d01
	  section.data(1).logicalSrcIdx = 167;
	  section.data(1).dtTransOffset = 0;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_in
	  section.data(2).logicalSrcIdx = 168;
	  section.data(2).dtTransOffset = 1;
	
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.obj_j
	  section.data(3).logicalSrcIdx = 169;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.One_time_initialization.One_time_initialization_SubsysR
	  section.data(1).logicalSrcIdx = 170;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.ResettableSubsystem_o.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 187;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% load_arduino_v_15_loop_DW.ResettableSubsystem.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 188;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
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


  targMap.checksum0 = 521813789;
  targMap.checksum1 = 1415042592;
  targMap.checksum2 = 4278961723;
  targMap.checksum3 = 3306134440;

