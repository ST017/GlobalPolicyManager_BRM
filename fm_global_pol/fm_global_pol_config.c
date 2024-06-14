/* continuus file information --- %full_filespec: fm_global_pol_config.c~7.1.3:csrc:1 % */
/*******************************************************************
 *
 *  @(#) %full_filespec: fm_global_pol_config.c~7.1.3:csrc:1 %
 *
 *      Copyright (c) 1999 - 2006 Oracle. All rights reserved.
 *
 *      This material is the confidential property of Oracle Corporation
 *      or its subsidiaries or licensors and may be used, reproduced, stored
 *      or transmitted only in accordance with a valid Oracle license or
 *      sublicense agreement.
 *
 *******************************************************************/

#ifndef lint
static  char    Sccs_id[] = "@(#)%Portal Version: fm_global_pol_config.c:ServerIDCVelocityInt:2:2006-Sep-06 16:41:23 %";
#endif

#include <stdio.h>	/* for FILE * in pcm.h */
#include "pcm.h"
#include "cm_fm.h"
#include "ops/cust.h"
#include "cust_flds_ops.h"

#ifdef MSDOS
__declspec(dllexport) void * fm_global_pol_config_func();
#endif

/*******************************************************************
 *******************************************************************/
struct cm_fm_config fm_global_pol_config[] = {
	/* opcode as a u_int, function name (as a string) */
	
        { PCM_OP_CUST_POL_PRE_COMMIT,           "op_global_pol_main" },
        { PCM_OP_CUST_POL_POST_COMMIT,          "op_global_pol_main" },
      //  { PCM_OP_CUST_POL_PRE_CREATE,          "op_global_pol_main" },
      //  { PCM_OP_CUST_POL_PREP_BILLINFO,           "op_gobal_pol_main" },
       //   { PCM_OP_CUST_POL_GET_CONFIG,		"op_global_pol_main" 	},
/*	{ PCM_OP_CUST_POL_GET_INTRO_MSG,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_PLANS,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_DEALS,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_PRODUCTS,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_POPLIST,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_ACCTINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_BILLINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_NAMEINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_AACINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_INHERITED,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_PASSWD,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_LOCALE,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_LOGIN,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_LIMIT,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_STATUS,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_ACCTINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_BILLINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_NAMEINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_AACINFO,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_INHERITED,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_PASSWD,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_LOGIN,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_LOCALE,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_LIMIT,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_STATUS,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_COMPARE_PASSWD,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_ENCRYPT_PASSWD,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_DECRYPT_PASSWD,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_EXPIRATION_PASSWD,	"op_global_pol_main"	}, 
	{ PCM_OP_CUST_POL_PREP_PROFILE,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_PROFILE,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_PAYINFO,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_PAYINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_MODIFY_SERVICE,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_CANONICALIZE, 	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_TAXINFO, 	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_DB_NO, 		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_READ_PLAN, 		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_TAX_INIT, 		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_TAX_CALC, 		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_DB_LIST,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_SET_BRANDINFO,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_POST_MODIFY_CUSTOMER,	"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_TRANSITION_DEALS,     "op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_TRANSITION_PLANS,     "op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_GET_SUBSCRIBED_PLANS, "op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_VALID_TOPUP,		"op_global_pol_main" 	},
	{ PCM_OP_CUST_POL_PREP_TOPUP,		"op_global_pol_main" 	},
    { PCM_OP_CUST_POL_PRE_DELETE_PAYINFO,	"op_global_pol_main" 	},
    
  //  fm_act_pol
  
         { PCM_OP_ACT_POL_EVENT_LIMIT,	"op_global_pol_main"  },
      { PCM_OP_ACT_POL_EVENT_NOTIFY,	"op_global_pol_main"  },
      { PCM_OP_ACT_POL_SPEC_VERIFY,	"op_global_pol_main"  },
      { PCM_OP_ACT_POL_SPEC_RATES,	"op_global_pol_main"  },
      { PCM_OP_ACT_POL_SPEC_GLID,	"op_global_pol_main"  },
      { PCM_OP_ACT_POL_VALIDATE_SCHEDULE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_SPEC_EVENT_CACHE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_SPEC_CANDIDATE_RUMS,"op_global_pol_main"  },
      { PCM_OP_ACT_POL_CONFIG_BILLING_CYCLE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_PRE_AUTHORIZE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_POST_AUTHORIZE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_PRE_REAUTHORIZE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_POST_REAUTHORIZE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_SCALE_MULTI_RUM_QUANTITIES, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_LOCK_SERVICE, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_LOG_USER_ACTIVITY, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_SET_RESOURCE_STATUS, "op_global_pol_main"  },
      { PCM_OP_ACT_POL_PROCESS_EVENTS, ""op_global_pol_main"  },   
      //fm_adu_pol
      { PCM_OP_ADU_POL_DUMP, "op_global_pol_main"  },
      { PCM_OP_ADU_POL_VALIDATE, "op_global_pol_main"  },
      
      //fm_apn_pol
          { PCM_OP_APN_POL_DEVICE_ASSOCIATE,	"op_global_pol_main"  },
	{ PCM_OP_APN_POL_DEVICE_CREATE,		"op_global_pol_main"  }, 
	{ PCM_OP_APN_POL_DEVICE_DELETE,		"op_global_pol_main"  }, 
	{ PCM_OP_APN_POL_DEVICE_SET_ATTR,	"op_global_pol_main"  }, 
	{ PCM_OP_APN_POL_DEVICE_SET_BRAND,	"op_global_pol_main"  }, 
	{ PCM_OP_APN_POL_DEVICE_SET_STATE,	"op_global_pol_main"  }, 
 
 //fm_ar_pol
 	{ PCM_OP_AR_POL_REVERSE_WRITEOFF,               "op_global_pol_main"  },
         { PCM_OP_AR_POL_GET_EVENT_RUM_CHARGE_DETAIL,    "op_global_pol_main"  },     
         { PCM_OP_AR_POL_PRE_EVENT_ADJUSTMENT,           "op_global_pol_main"  },           
         { PCM_OP_AR_POL_GET_BILLS,                      "op_global_pol_main"  },   
         
      //   fm_bal_pol
  { PCM_OP_BAL_POL_CHECK_LIFECYCLE_STATE, "op_global_pol_main"  },
{ PCM_OP_BAL_POL_APPLY_MULTI_BAL_IMPACTS, "op_global_pol_main"  },

//fm_bill_pol

  { PCM_OP_BILL_POL_VALID_DISPUTE,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_VALID_SETTLEMENT, 	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_VALID_ADJUSTMENT,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_VALID_TRANSFER,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_VALID_WRITEOFF,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_SPEC_BILLNO,		"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_BILL_PRE_COMMIT,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_SPEC_FUTURE_CYCLE,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_GET_PENDING_ITEMS, "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_POST_BILLING, "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_CALC_PYMT_DUE_T, "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_CHECK_SUPPRESSION, "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_EVENT_SEARCH, "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_REVERSE_PAYMENT,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_CONFIG_BILLING_CYCLE,	"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_GET_ITEM_TAG,		"op_global_pol_main"  },
	{ PCM_OP_BILL_POL_GET_EVENT_SPECIFIC_DETAILS,   "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_VALID_CORRECTIVE_BILL,   "op_global_pol_main"  },
	{ PCM_OP_BILL_POL_ITEM_REFUND,   "op_global_pol_main"  },
  
  //fm_collections_pol
  
  { PCM_OP_COLLECTIONS_POL_SELECT_PROFILE, 
		"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_EXEC_POLICY_ACTION, 
		"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_PREP_DUNNING_DATA, 
		"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_EXIT_SCENARIO, 
			"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_APPLY_LATE_FEES, 
		"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_ASSIGN_AGENT, 
		"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_APPLY_FINANCE_CHARGES, 
		"op_global_pol_main"  },

 	{ PCM_OP_COLLECTIONS_POL_CALC_DUE_DATE,
			"op_global_pol_main"  },

       { PCM_OP_COLLECTIONS_POL_PROCESS_BILLINFO,
                        "op_global_pol_main"  },
                        
       //fm_content_pol 
                       
   { PCM_OP_CONTENT_POL_ACCOUNTING,	"op_global_pol_main"  },
	{ PCM_OP_CONTENT_POL_AUTHORIZE,		"op_global_pol_main"  },
	{ PCM_OP_CONTENT_POL_RESOLVE_EVENT_EXTENSIONS,
					"op_global_pol_main"  },
	{ PCM_OP_CONTENT_POL_RESOLVE_USER,
					"op_global_pol_main"  },
	{ PCM_OP_CONTENT_POL_POST_AUTHORIZE,	
					"op_global_pol_main"  },
	{ PCM_OP_CONTENT_POL_POST_ACCOUNTING,	
					"op_global_pol_main"  }, 
 
 // fm_device_pol 
 
 { PCM_OP_DEVICE_POL_CREATE,		"op_global_pol_main"  },
	{ PCM_OP_DEVICE_POL_SET_STATE,		"op_global_pol_main"  },
	{ PCM_OP_DEVICE_POL_SET_ATTR,		"op_global_pol_main"  },
	{ PCM_OP_DEVICE_POL_ASSOCIATE,		"op_global_pol_main"  },
	{ PCM_OP_DEVICE_POL_DELETE,		"op_global_pol_main"  },
	{ PCM_OP_DEVICE_POL_REPLACE,		"op_global_pol_main"  },
	{ PCM_OP_DEVICE_POL_SET_BRAND,		"op_global_pol_main"  },
 
 //fm_gl_pol
 { PCM_OP_GL_POL_EXPORT_GL,		
		(char *)"op_global_pol_main"  },
	 { PCM_OP_GL_POL_PRE_UPDATE_JOURNAL,		
		(char *)"op_global_pol_main"  },
   
   //fm_ifw_sync_pol
   
   { PCM_OP_IFW_SYNC_POL_PUBLISH_EVENT,	"op_global_pol_main" },
 
 
 //fm_inv_pol
 
 	
		{ PCM_OP_INV_POL_PREP_INVOICE,  	  "op_global_pol_main"  },
	{ PCM_OP_INV_POL_FORMAT_INVOICE,	  "op_global_pol_main"  },
	{ PCM_OP_INV_POL_FORMAT_VIEW_INVOICE, "op_global_pol_main"  },
	{ PCM_OP_INV_POL_FORMAT_INVOICE_HTML, "op_global_pol_main"  },
	{ PCM_OP_INV_POL_FORMAT_INVOICE_DOC1, "op_global_pol_main"  },
	{ PCM_OP_INV_POL_FORMAT_INVOICE_XML,  "op_global_pol_main"  },
	{ PCM_OP_INV_POL_FORMAT_INVOICE_XSLT, "op_global_pol_main"  },
	{ PCM_OP_INV_POL_SELECT, 			  "op_global_pol_main"  },
	{ PCM_OP_INV_POL_POST_MAKE_INVOICE,   "op_global_pol_main"  },
 
 //fm_ip_pol
 
 { PCM_OP_IP_POL_DEVICE_ASSOCIATE,	"op_global_pol_main"  },
	{ PCM_OP_IP_POL_DEVICE_CREATE,		"op_global_pol_main"  },
	{ PCM_OP_IP_POL_DEVICE_DELETE,		"op_global_pol_main"  },
	{ PCM_OP_IP_POL_DEVICE_SET_ATTR,	"op_global_pol_main"  },
	{ PCM_OP_IP_POL_DEVICE_SET_BRAND,	"op_global_pol_main"  },
	{ PCM_OP_IP_POL_DEVICE_SET_STATE,	"op_global_pol_main"  },
 
 //fm_num_pol
 
 	 { PCM_OP_NUM_POL_CANONICALIZE, "op_global_pol_main"  },
        { PCM_OP_NUM_POL_DEVICE_ASSOCIATE, "op_global_pol_main"  },
        { PCM_OP_NUM_POL_DEVICE_CREATE, "op_global_pol_main"  },
        { PCM_OP_NUM_POL_DEVICE_SET_ATTR, "op_global_pol_main"  },
        { PCM_OP_NUM_POL_DEVICE_SET_BRAND, "op_global_pol_main"  },
        { PCM_OP_NUM_POL_DEVICE_DELETE, "op_global_pol_main"  },
		
		//fm_order_pol
		
		{ PCM_OP_ORDER_POL_ASSOCIATE,		"op_global_pol_main"  },
	{ PCM_OP_ORDER_POL_CREATE,		"op_global_pol_main"  },
	{ PCM_OP_ORDER_POL_DELETE,		"op_global_pol_main"  },
	{ PCM_OP_ORDER_POL_PROCESS,		"op_global_pol_main"  },
	{ PCM_OP_ORDER_POL_SET_ATTR,		"op_global_pol_main"  },
	{ PCM_OP_ORDER_POL_SET_BRAND,		"op_global_pol_main"  },
	{ PCM_OP_ORDER_POL_SET_STATE,		"op_global_pol_main"  },
		
		
		//fm_price_pol
		
	{ PCM_OP_PRICE_POL_DELETE_DEAL, 	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_DELETE_PRODUCT,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_DELETE_DISCOUNT,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_DELETE_DEPENDENCY,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_DELETE_TRANSITION,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_PREP_DEAL,		"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_PREP_PRODUCT,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_PREP_DISCOUNT,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_PREP_DEPENDENCY,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_PREP_TRANSITION,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_VALID_DEAL,		"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_VALID_PRODUCT,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_VALID_DISCOUNT,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_VALID_DEPENDENCY,	"op_global_pol_main" },
	{ PCM_OP_PRICE_POL_VALID_TRANSITION,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_PREP_PIPELINE_DISCOUNTMODEL,	"op_global_pol_main"  },
	{ PCM_OP_PRICE_POL_VALID_PIPELINE_DISCOUNTMODEL, "op_global_pol_main"  },
		
		
		
		
		
		//fm_process_audit_pol

    
	{ PCM_OP_PROCESS_AUDIT_POL_CREATE, "op_global_pol_main"  },
	{ PCM_OP_PROCESS_AUDIT_POL_CREATE_AND_LINK, "op_global_pol_main"  },
	{ PCM_OP_PROCESS_AUDIT_POL_ALERT, "op_global_pol_main"  },
	{ PCM_OP_PROCESS_AUDIT_POL_CREATE_WRITEOFF_SUMMARY, "op_global_pol_main"  },		
	
	
	
	
	
	
	//fm_prov_pol
	
	 
 { PCM_OP_PROV_POL_UPDATE_SVC_ORDER,	"op_global_pol_main" },
 
 //fm_pymt_pol
 
 { PCM_OP_PYMT_POL_VALID_VOUCHER,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_PURCHASE_DEAL,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_PRE_COLLECT,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_COLLECT,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_VALIDATE,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_UNDER_PAYMENT,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_OVER_PAYMENT,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_SPEC_COLLECT,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_SPEC_VALIDATE,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_GRANT_INCENTIVE,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_APPLY_FEE,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_CHARGE,		"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_VALIDATE_PAYMENT,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_PROVISION_INCENTIVE,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_SUSPEND_PAYMENT,	"op_global_pol_main"  },
	{ PCM_OP_PYMT_POL_MBI_DISTRIBUTE,	"op_global_pol_main"  },
      { PCM_OP_PYMT_POL_PRE_REFUND,       "op_global_pol_main"  },
      { PCM_OP_PYMT_POL_POST_REFUND,       "op_global_pol_main"  },
	  
     //fm_rate_pol
	  
	  { PCM_OP_RATE_POL_TAX_LOC,		"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_POST_RATING,		"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_GET_TAX_SUPPLIER,	"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_MAP_TAX_SUPPLIER,	"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_PRE_TAX,		"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_POST_TAX,		"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_GET_TAXCODE,		"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_EVENT_ZONEMAP,	"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_PRE_RATING,		"op_global_pol_main"  },
	{ PCM_OP_RATE_POL_PROCESS_ERAS,		"op_global_pol_main"  },
	  
	  //fm_remit_pol
     
	   { PCM_OP_REMIT_POL_SPEC_QTY, "op_global_pol_main" },
       
	   //fm_repl_pol
       
	   	{ PCM_OP_REPL_POL_PUSH, "op_global_pol_main" },
		
		 //fm_sim_pol
      
		{PCM_OP_SIM_POL_DEVICE_ASSOCIATE,	"op_global_pol_main"  },
	{ PCM_OP_SIM_POL_DEVICE_CREATE,		"op_global_pol_main"  },
	{ PCM_OP_SIM_POL_DEVICE_SET_ATTR,	"op_global_pol_main"  },
	{ PCM_OP_SIM_POL_DEVICE_SET_BRAND,	"op_global_pol_main"  },
	{ PCM_OP_SIM_POL_ORDER_CREATE, "op_global_pol_main"  },
	
	
	
 //	fm_subscription_pol
	
	
	
	{ PCM_OP_SUBSCRIPTION_POL_PRE_FOLD,             
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_PREP_FOLD,             
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_PURCHASE_PROD_PROVISIONING,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_CANCEL_PROD_PROVISIONING,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_GET_PROD_PROVISIONING_TAGS,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_SPEC_CYCLE_FEE_INTERVAL,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_SPEC_CANCEL, 
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_SPEC_CANCEL_DISCOUNT, 
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_GET_SPONSORS, 
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_SPEC_FOLD, 
		(char *)"op_global_pol_main"  },
		{ PCM_OP_SUBSCRIPTION_POL_SNOWBALL_DISCOUNT, 
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_SPEC_RERATE,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_CONFIG_EET,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_PRE_TRANSITION_DEAL,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_PRE_TRANSITION_PLAN,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_PREP_MEMBERS,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_COUNT_LINES,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_NOTIFY_AGGREGATION,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_UPDATE_CDC,
		(char *)"op_global_pol_main"  },
	{ PCM_OP_SUBSCRIPTION_POL_AUTO_SUBSCRIBE_MEMBERS,
		(char *)"XXXXX" },
	{ PCM_OP_SUBSCRIPTION_POL_AUTO_SUBSCRIBE_SERVICE,
		(char *)"XXXXX" },
	{ PCM_OP_SUBSCRIPTION_POL_GENERATE_RERATE_REQUEST,
		(char *)"XXXXX" },
        { PCM_OP_SUBSCRIPTION_POL_POST_TRANSFER_SUBSCRIPTION,
                (char *)"op_global_pol_main"  },
                
                
                
          //fm_tcf_pol
   { PCM_OP_TCF_POL_APPLY_PARAMETER, \
"op_global_pol_main"  },
/*	{ PCM_OP_TCF_POL_PROV_HANDLE_SVC_ORDER, \
"op_global_pol_main"  },

 // fm_term_pol
{ PCM_OP_TERM_POL_AUTHORIZE,		"op_global_pol_main"  },
	{ PCM_OP_TERM_POL_REVERSE_IP,		"op_global_pol_main"  },
	{ PCM_OP_TERM_POL_ACCOUNTING,		"op_global_pol_main"  },    
  
  //fm_trans_pol
  
  		{ PCM_OP_TRANS_POL_OPEN,		"op_global_pol_main"  },
	{ PCM_OP_TRANS_POL_PREP_COMMIT,		"op_global_pol_main"  },
	{ PCM_OP_TRANS_POL_COMMIT,		"op_global_pol_main"  },
	{ PCM_OP_TRANS_POL_ABORT,		"op_global_pol_main"  },
  
  //fm_vocher_pol
  { PCM_OP_VOUCHER_POL_ORDER_CREATE,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_ORDER_SET_ATTR,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_ORDER_SET_BRAND,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_ORDER_DELETE,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_ORDER_ASSOCIATE,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_ORDER_PROCESS,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_DEVICE_ASSOCIATE,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_DEVICE_CREATE,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_DEVICE_SET_ATTR,	"op_global_pol_main"  },
	{ PCM_OP_VOUCHER_POL_DEVICE_SET_BRAND,	"op_global_pol_main"  },
  
  //fm_zonemap_pol
  { PCM_OP_ZONEMAP_POL_GET_ZONEMAP,     "op_global_pol_main"  },
	{ PCM_OP_ZONEMAP_POL_SET_ZONEMAP,     "op_global_pol_main"  },
	{ PCM_OP_ZONEMAP_POL_GET_LINEAGE,     "op_global_pol_main"  },  */
                
 
	      { 0,	(char *)0 }
};

#ifdef MSDOS
void *
fm_global_pol_config_func()
{
  return ((void *) (fm_global_pol_config));
}
#endif

