function [KCmdE,KCLdE,CmdE,CLdE]=Equilibratore(OGb,A,B,K)
%Funzione per calcolo dei coefficienti di forza e momento in 1/deg e 1/rad
%legati al comando sull'equilibratore; Lo spostamento nel baricentro è
%fatto dando in input le coordinate del baricentro da fuori



dEvec=0:2:6;


% Importo risultati sempre con ciclo for come sopra
cd EQUILIBRATORE
clear i
i=1;
FxdE=zeros(1,4);
FydE=zeros(1,4);
FzdE=zeros(1,4);
MxdE=zeros(1,4);
MydE=zeros(1,4);
MzdE=zeros(1,4);

for dE=0:2:6
    
    dE_1=num2str(dE);
    cartelladE=strcat('dE=',dE_1);
    cd(cartelladE)
    
    load minfo1_e1.csv
    load minfo1_e2.csv
    load minfo1_e3.csv
    load minfo1_e4.csv
    load minfo1_e5.csv
    load minfo1_e6.csv
    FxdE(i)=minfo1_e1(end,3);
    FydE(i)=minfo1_e2(end,3);
    FzdE(i)=minfo1_e3(end,3);
    MxdE(i)=minfo1_e4(end,3);
    MydE(i)=minfo1_e5(end,3);
    MzdE(i)=minfo1_e6(end,3);
    clear minfo1_e1
    clear minfo1_e2
    clear minfo1_e3
    clear minfo1_e4
    clear minfo1_e5
    clear minfo1_e6
    cd ..
    
    i=i+1;
end

cd ..
%sposto i momenti e nel baricentro

clear i

FxbdE=zeros(1,4);
FybdE=zeros(1,4);
FzbdE=zeros(1,4);
MxbdE=zeros(1,4);
MybdE=zeros(1,4);
MzbdE=zeros(1,4);

for i=1:4
    
    % forze
    RwdE=[FxdE(i) 0 FzdE(i)]';
    RbdE=RwdE;
    FxbdE(i)=RbdE(1);
    FybdE(i)=RbdE(2);
    FzbdE(i)=RbdE(3);
        
    % momenti
    MowdE=[0 MydE(i) 0]';
    MgdE=MowdE+cross(OGb,RbdE);
    MxbdE(i)=MgdE(1);
    MybdE(i)=MgdE(2);
    MzbdE(i)=MgdE(3);
    
    clear RwdE RbdE MowdE MgdE
end



% calcolo dei coefficienti con formula linearizzata
% adimensionalizzazione
CMybdE=MybdE./K;
CFzwdE=FzdE./A;
% interpolazione (1/deg)
KCmdE=polyfit(dEvec,CMybdE,1);
KCLdE=polyfit(dEvec,-CFzwdE,1);
% conversione in 1/rad
CmdE=KCmdE(1)*180/pi;
CLdE=KCLdE(1)*180/pi;

end