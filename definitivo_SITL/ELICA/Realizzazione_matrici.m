%Codice di realizzazione matrici

%Con questo codice si realizzano le matrici di Ct e Cp dove ogni colonna
%rappresenta un dato valore di RPM mentre ogni riga rappresenta un rapporto
%di avanzamento, i rapporti per cui sono date le prestazioni dell'elica sono 30
%e sono circa uguali per ogn valore di RPM, Ad alti RPM differiscono di
%0.001 al limite dunque verranno considerati uguali per semplicità.

load('propData')

%Nelle matrici di caricamento il Ct è la 3° colonna mentre il Cp è la 4°


RPM_vec=[0,1000:1000:11000]; %vettore degli RPM
J_vec=RPM1K(:,2); %Vettore del rapporto di avamzamento J=V/(nD) con n=giri/s e D=diametro; è adimensionale dunque si possono usare V in m/s e D in m  

% Ct      [Ct=T/(rho*n^2*D^4)] ADIMENSIONALE
Ct=zeros(31,12);
Ct(2:end,1)=J_vec;
Ct(1,:)=RPM_vec;
Ct(2:end,2:end)=[RPM1K(:,3),RPM2K(:,3),RPM3K(:,3),RPM4K(:,3),RPM5K(:,3),RPM6K(:,3),RPM7K(:,3),RPM8K(:,3),RPM9K(:,3),RPM10K(:,3),RPM11K(:,3)];

% Cp      [Cp=P/(rho*n^3*D^5)] ADIMENSIONALE
Cp=zeros(31,12);
Cp(2:end,1)=J_vec;
Cp(1,:)=RPM_vec;
Cp(2:end,2:end)=[RPM1K(:,4),RPM2K(:,4),RPM3K(:,4),RPM4K(:,4),RPM5K(:,4),RPM6K(:,4),RPM7K(:,4),RPM8K(:,4),RPM9K(:,4),RPM10K(:,4),RPM11K(:,4)];