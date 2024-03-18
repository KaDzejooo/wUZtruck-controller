/*
 * app_user.h
 *
 *  Created on: Jun 28, 2023
 *      Author: oem
 */

#ifndef APP_APP_USER_H_
#define APP_APP_USER_H_

#ifdef __cplusplus
 extern "C" {
#endif

 // create all task external main references here
 //void StartAssTask(yelp);

 void StartUartComms(void *argument);
 void StartVideoDecode(void *argument);
 void StartTaskIO(void *argument);
 void StartIntegrityMngr(void *argument);

#ifdef __cplusplus
 }
#endif

#endif /* APPLICATION_USER_USERLIB_APP_APP_USER_H_ */
