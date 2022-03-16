function  [CD,CY,CL,CMxw,CMyw,CMzw,Cl,Cm,Cn,CFxb,CFyb,CFzb]=calcoloPolari(OGb,A,B,K)
%Funzione che richiama i dati dalla simulazione aerodinamica e calcola 12
%tabelle per forze e momenti in assi vento e forze e momenti in assi corpo
%il vettore baricentro viene dato in input e rappresenta le coordinte del
%polo rispetto al baricentro
%prova


alphavec=[-6:6];
betavec=[-12:4:12];

cd POLARI

j=1;

    for beta=0:4:12



        beta_1=num2str(beta);
        cartellaBeta=strcat('BETA=',beta_1);
        cd(cartellaBeta)

        i=1;

        for alfa=-6:6

            alfa_1=num2str(alfa);
            cartellaAlfa=strcat('ALPHA=',alfa_1);
            cd(cartellaAlfa)

            load minfo1_e1.csv 
            load minfo1_e2.csv
            load minfo1_e3.csv
            load minfo1_e4.csv
            load minfo1_e5.csv
            load minfo1_e6.csv

            D(i,j)=-minfo1_e1(end,3);
            C(i,j)=-minfo1_e2(end,3);
            L(i,j)=-minfo1_e3(end,3);
            Mxw(i,j)=minfo1_e4(end,3);
            Myw(i,j)=minfo1_e5(end,3);
            Mzw(i,j)=minfo1_e6(end,3);

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
        j=j+1;
    end
cd ..

dim=size(D);
c1=dim(2);
r=dim(1);

% Le forze parallele agli assi vento sono quindi: queste forze hanno
% come base la terna vento orientata con Z verso il basso e X verso
% davanti come abbiamo studiato a DV
Fxw=-D;
Fyw=-C;
Fzw=-L;

%copletamento delle forze e momenti per beta negativi
Fxw=[zeros(r,c1-1) Fxw];
Fyw=[zeros(r,c1-1) Fyw];
Fzw=[zeros(r,c1-1) Fzw];
Mxw=[zeros(r,c1-1) Mxw];
Myw=[zeros(r,c1-1) Myw];
Mzw=[zeros(r,c1-1) Mzw];
D=[zeros(r,c1-1) D];
C=[zeros(r,c1-1) C];
L=[zeros(r,c1-1) L];

% ricalcolo delle dimensioni delle matrici

clear dim
clear r
dim=size(D);
c=dim(2);
r=dim(1);

lun=c1-1;
for i=1:lun
    Fxw(:,i)=Fxw(:,c+1-i);
    Fyw(:,i)=-Fyw(:,c+1-i);
    Fzw(:,i)=Fzw(:,c+1-i);
    Mxw(:,i)=-Mxw(:,c+1-i);
    Myw(:,i)=Myw(:,c+1-i);
    Mzw(:,i)=-Mzw(:,c+1-i);
    D(:,i)=D(:,c+1-i);
    C(:,i)=-C(:,c+1-i);
    L(:,i)=L(:,c+1-i);
end

C(:,c1)=0; 
Fyw(:,c1)=0; 
Mxw(:,c1)=0; 
Mzw(:,c1)=0;

% tabelle per le forze in assi vento
%Coefficiente di Resistenza
CD=zeros(r+1,c+1);
CD(:,1)=[0 alphavec]';
CD(1,2:end)=betavec;
CD(2:end,2:end)=D./A;

%CY= inverso del coefficiente di devianza
CY=zeros(r+1,c+1);
CY(:,1)=[0 alphavec]';
CY(1,2:end)=betavec;
CY(2:end,2:end)=Fyw./A; %qui forse ci va C e non Fyw che compare per altro anche sotto

%Coefficiente di Portanza
CL=zeros(r+1,c+1);
CL(:,1)=[0 alphavec]';
CL(1,2:end)=betavec;
CL(2:end,2:end)=L./A;

%Coefficiente di forza lungo l'asse z wind
CFzw=zeros(r+1,c+1);
CFzw(:,1)=[0 alphavec]';
CFzw(1,2:end)=betavec;
CFzw(2:end,2:end)=Fzw./A;

%Coefficiente di momento lungo l'asse x wind quindi sarebbe l
CMxw=zeros(r+1,c+1);
CMxw(:,1)=[0 alphavec]';
CMxw(1,2:end)=betavec;
CMxw(2:end,2:end)=Mxw./B;

%Coefficiente di momento lungo l'asse y wind 
CMyw=zeros(r+1,c+1);
CMyw(:,1)=[0 alphavec]';
CMyw(1,2:end)=betavec;
CMyw(2:end,2:end)=Myw./K;

%Coefficiente di momento lungo l'asse z wind quindi N
CMzw=zeros(r+1,c+1);
CMzw(:,1)=[0 alphavec]';
CMzw(1,2:end)=betavec;
CMzw(2:end,2:end)=Mzw./B;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%Spostamento nel baricentro e rotazione in assi corpo


LBW=zeros(3,3);
Rw=[];
Rb=[];
Mow=[];
Mob=[];
Mg=[];

% ciclo per l rotazione di forze e momenti per ogni alfa e beta gia
% definiti in alfavec e beta vec

j=1;
Fxb=zeros(r,c);
Fyb=zeros(r,c);
Fzb=zeros(r,c);

Mxb=zeros(r,c);
Myb=zeros(r,c);
Mzb=zeros(r,c);

for beta=-12:4:12
    i=1;
    
    for alfa=-6:6
        %La matrice viene ricalcolata ad ogni passo per semplicità
        
         LBW=[cosd(alfa)*cosd(beta) -cosd(alfa)*sind(beta) -sind(alfa);
              sind(beta) cosd(beta) 0;
              sind(alfa)*cosd(beta) -sind(alfa)*sind(beta) cosd(alfa)]; 
         
         % forze (occorre semplicemente proiettare da terna vento a terna body)
         Rw=[Fxw(i,j) Fyw(i,j) Fzw(i,j)]';
         Rb=LBW*Rw;
         Fxb(i,j)=Rb(1);
         Fyb(i,j)=Rb(2);
         Fzb(i,j)=Rb(3);
         
         %momenti (oltre alla proiezione bisogna effettuare la traslazione, le forze scritte in assi corpo vanno applicate nel polo del calcolo della simulazione aerodinamica)
         Mow=[Mxw(i,j) Myw(i,j) Mzw(i,j)]';
         Mob=LBW*Mow;
         Mg=Mob+cross(OGb,Rb); %si rimanda alle prime righe della funzione CalcoloDatiCicloFor per conoscere il significato del vettore OGb
         Mxb(i,j)=Mg(1);
         Myb(i,j)=Mg(2);
         Mzb(i,j)=Mg(3);
          
       
         i=i+1; 
         clear Rw Rb Mow Mob Mg
    end
    j=j+1;
end


% Creo le tabelle dei momenti in assi corpo
%coeff di momento di rollio
Cl=zeros(r+1,c+1);
Cl(:,1)=[0 alphavec]';
Cl(1,2:end)=betavec;
Cl(2:end,2:end)=Mxb./B;
%coeff di momento di beccheggio
Cm=zeros(r+1,c+1);
Cm(:,1)=[0 alphavec]';
Cm(1,2:end)=betavec;
Cm(2:end,2:end)=Myb./K;
%coeff di momento di imbardata
Cn=zeros(r+1,c+1);
Cn(:,1)=[0 alphavec]';
Cn(1,2:end)=betavec;
Cn(2:end,2:end)=Mzb./B;
%coeff di forza lungo l'asse x body
CFxb=zeros(r+1,c+1);
CFxb(:,1)=[0 alphavec]';
CFxb(1,2:end)=betavec;
CFxb(2:end,2:end)=Fxb./A;
%coeff di forza lungo l'asse y body
CFyb=zeros(r+1,c+1);
CFyb(:,1)=[0 alphavec]';
CFyb(1,2:end)=betavec;
CFyb(2:end,2:end)=Fyb./A;
%coeff di forza lungo l'asse z body
CFzb=zeros(r+1,c+1);
CFzb(:,1)=[0 alphavec]';
CFzb(1,2:end)=betavec;
CFzb(2:end,2:end)=Fzb./A;
%coeff di momento lungo l'asse x body (identico alla variabile Cl)
CMxb=zeros(r+1,c+1);
CMxb(:,1)=[0 alphavec]';
CMxb(1,2:end)=betavec;
CMxb(2:end,2:end)=Mxb./B;
%coeff di momento lungo l'asse y body (identico alla variabile Cm)
CMyb=zeros(r+1,c+1);
CMyb(:,1)=[0 alphavec]';
CMyb(1,2:end)=betavec;
CMyb(2:end,2:end)=Myb./K;
%coeff di momento lungo l'asse z body (identico alla variabile Cn)
CMzb=zeros(r+1,c+1);
CMzb(:,1)=[0 alphavec]';
CMzb(1,2:end)=betavec;
CMzb(2:end,2:end)=Mzb./B;

end