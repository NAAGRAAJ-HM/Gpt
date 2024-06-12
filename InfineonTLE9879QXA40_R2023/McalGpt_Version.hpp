#pragma once
/******************************************************************************/
/* File   : McalGpt_Version.hpp                                               */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define MCALGPT_AR_RELEASE_VERSION_MAJOR                                       4
#define MCALGPT_AR_RELEASE_VERSION_MINOR                                       3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(MCALGPT_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible MCALGPT_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(MCALGPT_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible MCALGPT_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

