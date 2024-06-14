/*******************************************************************
 *
 *      Copyright (c) 1999-2007 Oracle. All rights reserved.
 *
 *      This material is the confidential property of Oracle Corporation
 *      or its licensors and may be used, reproduced, stored or transmitted
 *      only in accordance with a valid Oracle license or sublicense agreement.
 *
 *******************************************************************/

#ifndef lint
static  char Sccs_Id[] = "@(#)%Portal Version: fm_global_pol.c:RWSmod7.3.1Int:1:2007-Jun-28 05:36:33 %";
#endif

#include <stdlib.h>
#include <stdio.h>
#include "pcm.h"
#include "ops/cust.h"
#include "cm_fm.h"
#include "pin_errs.h"
#include "pinlog.h"
#include "pin_cust.h"
#include "pin_bill.h"
#include "pinlog.h"
#include "pin_currency.h"
#include "psiu_currency.h"
#include "cust_flds_ops.h"
#include "global_fun.h"
#include <string.h>
#define MAX_LINE_LENGTH 100
#include <dlfcn.h>

EXPORT_OP void
op_global_pol_main(
        cm_nap_connection_t	*connp,
      	u_int			opcode,
        u_int			flags,
        pin_flist_t		*in_flistp,
        pin_flist_t		**ret_flistpp,
        pin_errbuf_t		*ebufp);

static void
fm_fw_search_opcode(
        pcm_context_t           *ctxp,
        u_int		              	*op_value,
        pin_flist_t		          *in_flistp,
        pin_flist_t             	**ret_flistpp,
        pin_errbuf_t            *ebufp);

/*******************************************************************
 * Main routine for the PCM_OP_CUST_POL_PRE_COMMIT  command
 *******************************************************************/
void
op_global_pol_main(
        cm_nap_connection_t	*connp,
	      u_int			opcode,
        u_int			flags,
        pin_flist_t		*in_flistp,
        pin_flist_t		**ret_flistpp,
        pin_errbuf_t		*ebufp)
{
  void    *handle;
	pcm_context_t		*ctxp = connp->dm_ctx;
	pin_flist_t		*r_flistp = NULL;
  pin_flist_t     *create_iflistp = NULL;	
  pin_flist_t     *create_rflistp = NULL;
  u_int *op_value = NULL;
  int value = 0 ;
  pin_flist_t *s_rflistp = NULL;
  pin_flist_t  *t1_1flistp = NULL;
  pin_flist_t  *op_resultp = NULL;
  int  *status_value = 0;
  char *func_name = NULL;
  char *so_name = NULL;
  int *opcode_number = 0;
  pin_flist_t *search_rflistp = NULL;
  pin_flist_t *sea_flistp = NULL;
  int valid = 1;
  //  void      *fptr;
  void  *eret;
  char *errstr;
  typedef void (*callin_function)(
        cm_nap_connection_t* connp,
        u_int opcode,
        u_int flags,
        pin_flist_t* in_flistp,
        pin_flist_t** ret_flistpp,
        pin_errbuf_t* ebufp);
        
        
    callin_function func ;


    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *name;
    
  // pin_flist_t *i_flistp = NULL;
  
	/***********************************************************
	 * Null out results until we have some.
	 ***********************************************************/
   
         	*ret_flistpp = NULL;
  
	      PIN_ERR_CLEAR_ERR(ebufp);

	/***********************************************************
	 * Insanity check.
	 ***********************************************************/

 
	/***********************************************************
	 * Call main function to do it
	 ***********************************************************/
     op_value = &opcode;
 
    fm_fw_search_opcode(ctxp, op_value, in_flistp, &search_rflistp, ebufp);
    
    
    
     
      PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
	                                        	"op_global_pol_main inside search results ", search_rflistp);
                                                                                      
    
         t1_1flistp = (void *)PIN_FLIST_ELEM_GET(search_rflistp, PIN_FLD_RESULTS, PIN_ELEMID_ANY, 0, ebufp );
    // null or not...
     if (t1_1flistp == NULL)
       {
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR, 
			" search_opcode output doen't have the PIN_FLD_RESULT add  the data to config_fm_gobal_pol_t table", ebufp);
      return;
    	}
     
    
    
         op_resultp = (void *)PIN_FLIST_ELEM_GET(t1_1flistp, PIN_FLD_OP_INFO, 0, 1, ebufp );
         
         func_name = PIN_FLIST_FLD_GET(op_resultp,  PIN_FLD_FUNCTION_NAME, 0, ebufp);
         so_name = PIN_FLIST_FLD_GET(op_resultp, PIN_FLD_SHARED_OBJECT, 0, ebufp);
         status_value = PIN_FLIST_FLD_GET(op_resultp, PIN_FLD_STATUS_VALUE, 0, ebufp);
         opcode_number =  PIN_FLIST_FLD_GET(op_resultp, PIN_FLD_OPCODE_VALUE, 0, ebufp);
         
         if ( status_value != NULL && (*status_value )== 1)
         {
         
          PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
	                                        	"op_global_pol_main inside status value 1", in_flistp);
                                                                                    
        
/* call the opcode 
 *
 */  
 
  /*
             file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file line by line
      while (fscanf(file, "%s %d", name, &value) != EOF) {
    
          PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
	                                        	"op_global_pol_main inside status value 1", name);
        // Print the name and value
      //  printf("Name: %s, Value: %d\n", name, value);
       }
 */
       /*     file = fopen("sample.txt", "r");
             if (file == NULL) {
              printf("Could not open file.\n");
             return 1;
           }

    // Read each line and extract the name and value
             while (fgets(line, sizeof(line), file)) {
        // Extract the name and value
             name = strtok(line, " ");
               if (name != NULL) {
            
              PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
	                                        	"op_global_pol_main inside status value 1", name);
               printf("Name: %s, Value: %d\n", name);
            }
       }
           
    // Close the file
            
         /*     fm_fw_search_opcode(ctxp, op_value, in_flistp, &search_rflistp, ebufp);
                t1_1flistp = (void *)PIN_FLIST_ELEM_GET(search_rflistp, PIN_FLD_RESULTS, PIN_ELEMID_ANY, 0, ebufp );
                  op_resultp = (void *)PIN_FLIST_ELEM_GET(t1_1flistp, PIN_FLD_OP_INFO, 0, 1, ebufp );
                  opcode_number =  PIN_FLIST_FLD_GET(op_resultp, PIN_FLD_OPCODE_VALUE, 0, ebufp); */
                  
           // 	sea_flistp = PIN_FLIST_CREATE(ebufp);
           
           sea_flistp = PIN_FLIST_COPY(in_flistp, ebufp);
             
       //    sea_flistp = PIN_FLIST_CONCAT(in_flistp, search_rflistp, ebufp );

        
      
        	PIN_FLIST_FLD_SET(sea_flistp, PIN_FLD_OPCODE,  (void *)opcode_number, ebufp);
       
          PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
	                                        	" checking  the opcode number is add to flist    ", sea_flistp);
 
 
          PCM_OP(ctxp, PCM_OP_CUST_EM, 0, sea_flistp, &create_rflistp, ebufp);	
          
          
          
		      *ret_flistpp = create_rflistp;
                
          //     fclose(file);

        
         }
         else {
         
         
         PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
	                                        	"op_global_pol_main inside status value 0  calling .so file  ", in_flistp);
         

/* open the needed object */
                  handle = dlopen(so_name, RTLD_LAZY );
                  
                  PIN_ERR_LOG_MSG( PIN_ERR_LEVEL_DEBUG, " calling  function from .so file ");
                  
/* find the address of function and data objects */
                
                   func = (callin_function)dlsym(handle, func_name);
                        
                  func(connp, opcode, flags, in_flistp, &ret_flistpp, &ebufp);
          
                  dlclose(handle);
                  
                  PIN_ERR_LOG_MSG( PIN_ERR_LEVEL_DEBUG, " closed the sharedobject .so file ");

         }
        
                  
   
	/***********************************************************
	 * Results.
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {
		*ret_flistpp = (pin_flist_t *)NULL;
		PIN_FLIST_DESTROY(r_flistp, NULL);
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_global_pol_main error", ebufp);
	} else {
		*ret_flistpp = r_flistp;
		PIN_ERR_CLEAR_ERR(ebufp);
		PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
			"op_global_pol_main return flist", r_flistp);
	}
 

	return;
}
/**************************************************
*  get data from the config_fm_global_pol_t 
* using search opcode 
***************************************************/

static void
fm_fw_search_opcode(
        pcm_context_t           *ctxp,
        u_int		              	*op_value,
        pin_flist_t	          	*in_flistp,
        pin_flist_t             	**ret_flistpp,
        pin_errbuf_t            *ebufp)
{

	pin_flist_t	*search_flistp = NULL;
 
	int64		db = 1;
	int64		id = -1;
	int32		flags = 256;
	char		*template =  "select X from /config/fm_global_pol where F1 = V1";
	pin_flist_t	*result_flistp = NULL;
	pin_flist_t	*search_rflistp = NULL;
	poid_t		*search_pdp = NULL;
	pin_flist_t     *args_flistp = NULL;
 	pin_flist_t     *op_info_array = NULL;
  pin_flist_t     *r_op_info_arry = NULL;
  int ld = 0;

/****************************************************
0 PIN_FLD_POID                     POID [0] 0.0.0.1 /search -1 0
0 PIN_FLD_FLAGS                    INT [0] 256
0 PIN_FLD_TEMPLATE                 STR [0] "select X from /config/fm_global_pol where F1 = V1"
0 PIN_FLD_ARGS                     ARRAY [1] allocated 1, used 1
1  PIN_FLD_OP_INFO                                 ARRAY [0]  allocated 1, used 1
2   PIN_FLD_OPCODE_VALUE    INT [0] 251
0 PIN_FLD_RESULTS                  ARRAY [*] allocated 2, used 2
1     PIN_FLD_OP_INFO       ARRAY [0] allocated 20, used 2
2      PIN_FLD_STATUS_VALUE    INT [0] 0
************************************************/  
     
  
	search_flistp = PIN_FLIST_CREATE(ebufp);
 
 
	search_pdp = PIN_POID_CREATE(db, "/search", id, ebufp);
 
	PIN_FLIST_FLD_SET(search_flistp, PIN_FLD_POID, search_pdp, ebufp);

	PIN_FLIST_FLD_SET(search_flistp, PIN_FLD_FLAGS, &flags, ebufp);
 
	PIN_FLIST_FLD_SET(search_flistp, PIN_FLD_TEMPLATE, template, ebufp);
 
 	args_flistp = PIN_FLIST_ELEM_ADD(search_flistp, PIN_FLD_ARGS, 1, ebufp);
  
  op_info_array = PIN_FLIST_ELEM_ADD(args_flistp, PIN_FLD_OP_INFO, 0, ebufp);
  
 	PIN_FLIST_FLD_SET(op_info_array, PIN_FLD_OPCODE_VALUE, (void *)op_value, ebufp);
  
  result_flistp = PIN_FLIST_ELEM_ADD(search_flistp, PIN_FLD_RESULTS, PIN_ELEMID_ANY, ebufp);
  r_op_info_arry = PIN_FLIST_ELEM_ADD(result_flistp, PIN_FLD_OP_INFO, 0, ebufp);
  

  
  
  
  
  if (PIN_ERR_IS_ERR(ebufp))
       {
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR, 
			"fm_fw_search_opcode_example having error while creating search flist", ebufp);
	}
	
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, 
		"fm_fw_search_opcode_example prepared input flist is", search_flistp);

 	PCM_OP(ctxp, PCM_OP_SEARCH, 0, search_flistp, &search_rflistp, ebufp);

	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, 
		"fm_fw_search_opcode_example prepared output flist is", search_rflistp);

	*ret_flistpp = search_rflistp;
	
 PIN_FLIST_DESTROY_EX(&search_flistp, ebufp);
 
	return;
 

}





