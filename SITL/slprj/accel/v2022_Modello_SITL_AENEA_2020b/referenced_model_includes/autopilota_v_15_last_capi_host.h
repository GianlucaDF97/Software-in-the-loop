#ifndef RTW_HEADER_autopilota_v_15_last_cap_host_h_
#define RTW_HEADER_autopilota_v_15_last_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
autopilota_v_15_last_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void autopilota_v_15_last_host_InitializeDataMapInfo (
autopilota_v_15_last_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
