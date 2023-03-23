
clear
dati=readmatrix('Dati_GPS.xlsx');
lat_max=max(dati(:,2));
lat_min=min(dati(:,2));
long_max=max(dati(:,3));
long_min=min(dati(:,3));

sigma_long_deg=abs(long_max-long_min)/2;
sigma_lat_deg=abs(lat_max-lat_min)/2;

sigma_long_rad=deg2rad(sigma_long_deg);
sigma_lat_rad=deg2rad(sigma_lat_deg);
