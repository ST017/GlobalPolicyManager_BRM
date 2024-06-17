# GlobalPolicyManager_BRM

Copy Include/cust_ops_flds.h file and paste at the inculde dir (where .h are present) run the pasre script( parse_custom_ops_fields.pl -L pcmc -I cust_ops_flds.h -O cust_ops_flds.o ) .o file will be generated 

add the extension in cm pin.conf ( ops_fields_extension_file path of.o file ex: - - ops_fields_extension_file /app/local/oracle/product/pin01/brm12/BRM/PortalDevKit/include/cust_flds_ops.o ) restart the cm

Copy the podl run pin_deploy script ( pin_deploy create fm_global_pol.podl ) restart the cm verify in the sql or developer center

Copy the fm_global_pol folder where all the fm are stored compile the file is in folder with "make all" command .so file will be generated add entry in cm pin.conf


add the data in config_fm_global_pol_t 
In flist folder there there are the sample flist data
load using testnap 

Copy the CustomEm folder to sys directory (ex:- /app/local/oracle/product/pin01/brm12/BRM/sys )
open the   start_em.sh script in the CustomEm

add the customem jar  to the classpath in the script 


# before customing the policy update the status_value in config_fm_global_pol_t ( if status value 1 then it override the existing policy code and goes to the globalpolicymanager and execute the custompolicy.jar. when status_value is 0 it does not override) 



 


