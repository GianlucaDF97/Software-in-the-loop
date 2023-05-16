lat=logsout.get("Lat_deg").Values;
long=logsout.get("Lon_deg").Values;
lat=reshape(lat.Data,[1,length(lat.Time)]);
long=reshape(long.Data,[1,length(long.Time)]);

waypoint=WP_db_param;
coordinate=waypoint(:,5:6);
posizione_iniziale=[41.89538064905558, 12.403498219629371];

geoplot(lat,long,"c","LineWidth",3)
hold on
geoplot(posizione_iniziale(1),posizione_iniziale(2),"ro",'Linewidth',1.5,"MarkerSize",8,"MarkerFaceColor","b")
hold on
for i=1:length(coordinate)
geoplot(coordinate(i,1),coordinate(i,2),"Vg",'Linewidth',1.5,"MarkerSize",10,"MarkerFaceColor","k")
end
geobasemap satellite