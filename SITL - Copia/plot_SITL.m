lat=logsout.get("Lat_deg").Values;
long=logsout.get("Lon_deg").Values;
lat=reshape(lat.Data,[1,length(lat.Time)]);
long=reshape(long.Data,[1,length(long.Time)]);

waypoint=[
            0 0 21 0 41.87933524903597, 12.705249320105622 60;
            0 0 22 0 41.88003981789205, 12.704562786031332 70;
            0 0 24 0 41.88107593445075, 12.70408035668183 80;
            0 0 20 0 41.88184955719275, 12.703560817382368 80;
            0 0 20 0 41.88244358259816, 12.703078388024485 60;
            0 0 20 0 41.88273368602881, 12.701946534429172 40;
            0 0 20 0 41.88325863173765, 12.700805403213348 50;... 
];
coordinate=waypoint(:,5:6);
posizione_iniziale=[rad2deg(latitudineINI), rad2deg(longitudineINI)];

geoplot(lat,long,"c","LineWidth",3)
hold on
geoplot(posizione_iniziale(1),posizione_iniziale(2),"ro",'Linewidth',1.5,"MarkerSize",8,"MarkerFaceColor","b")
hold on
for i=1:length(coordinate)
geoplot(coordinate(i,1),coordinate(i,2),"Vg",'Linewidth',1.5,"MarkerSize",10,"MarkerFaceColor","k")
end
geobasemap satellite