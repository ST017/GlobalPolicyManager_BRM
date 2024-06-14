#!/bin/sh
#
# Copyright (c) 2000, 2017, Oracle and/or its affiliates. All rights reserved.
#
#	This material is the confidential property of Oracle Corporation.
#	or its subsidiaries or licensors and may be used, reproduced, stored
#	or transmitted only in accordance with a valid Oracle license or
#	sublicense agreement.
#

#
# start_formatter
#
#
VERSION=__VERSION__
PATH=/usr/bin:/bin

PINDIR=/app/local/oracle/product/pin01/brm12/BRM

JSDIR=${PINDIR}/sys/Custem
LOGDIR=/app/local/oracle/product/pin01/brm12/BRM/var/Custem
JSLOG=${LOGDIR}/Custem.log
JSPID=${LOGDIR}/Custem.pid

if [ -r ${JSPID} ]; then
  /bin/ps -f -p `cat ${JSPID}` | grep Custem > /dev/null
  if [ $? -eq 0 ]; then
        echo "ERROR: Custem is already running"
        exit 1
  fi
fi

# does the propreties file for the Java Server
if [ ! -r  ${JSDIR}/Infranet.properties ]; then
		echo "HELP: no Infranet.properties for Custem in \"${JSDIR}\"!"
			exit 1
fi

if [ ! -d  ${LOGDIR} ]; then
	mkdir -p ${LOGDIR}
	if [ $? -ne 0 ]; then
		echo "HELP: problem making LOGDIR \"${LOGDIR}\"!"
		exit 1
	fi
fi

# set JAR_DIR to be the full pathname of the dir where the
# jar files are located
JAR_DIR=${PINDIR}/jars

#CLASSPATH=.:$JAR_DIR/Custem.jar:$JAR_DIR/js.jar:$JAR_DIR/pcm.jar:$JAR_DIR/oraclepki.jar:$JAR_DIR/osdt_cert.jar:$JAR_DIR/osdt_core.jar:$JAR_DIR/oracle9i/pcmext/pcmext9.jar:$JAR_DIR/ops.jar:$JAR_DIR/classgen.jar:$JAR_DIR/jstest.jar:$JAR_DIR/xerces.jar:$JAR_DIR/xt.jar:$JAR_DIR/xalan.jar:$JAR_DIR/serializer.jar:$JAR_DIR/saxon.jar:$JAR_DIR/sax.jar:$JAR_DIR/pxslt.jar:$JAR_DIR/xercesImpl.jar:$JAR_DIR/xmlParserAPIs.jar

#CLASSPATH=.:$JAR_DIR/ch.jar:$JAR_DIR/orginal_js.jar:$JAR_DIR/pcmext_9j.jar:$JAR_DIR/oraclepki.jar:$JAR_DIR/osdt_cert.jar:$JAR_DIR/osdt_core.jar:$JAR_DIR/oracle9i/pcm.jar:$JAR_DIR/classgen.jar:$JAR_DIR/jstest.jar:$JAR_DIR/xerces.jar:$JAR_DIR/xt.jar:$JAR_DIR/xalan.jar:$JAR_DIR/serializer.jar:$JAR_DIR/saxon.jar:$JAR_DIR/sax.jar:$JAR_DIR/pxslt.jar:$JAR_DIR/xercesImpl.jar:$JAR_DIR/xmlParserAPIs.jar
CLASSPATH=.:$JAR_DIR/orginal_js.jar:$JAR_DIR/CustomEM.jar:$JAR_DIR/oraclepki.jar:$JAR_DIR/osdt_cert.jar:$JAR_DIR/osdt_core.jar:$JAR_DIR/oracle9i/pcm.jar:$JAR_DIR/classgen.jar:$JAR_DIR/jstest.jar:$JAR_DIR/xerces.jar:$JAR_DIR/xt.jar:$JAR_DIR/xalan.jar:$JAR_DIR/serializer.jar:$JAR_DIR/saxon.jar:$JAR_DIR/sax.jar:$JAR_DIR/pxslt.jar:$JAR_DIR/xercesImpl.jar:$JAR_DIR/xmlParserAPIs.jar:$JAR_DIR/pcmext_9j.jar

export CLASSPATH

JAVA=/app/local/oracle/product/third_party/java/jdk1.8.0_281/bin/java

# XXX ought to save old log file, or check for > some-size...
( cd ${JSDIR} ;
  echo "started Custem at..." >> ${JSLOG}
  date >> ${JSLOG}
	$JAVA -DCustomEm=1 -mx33554432 -ms33554432 -ss1m com.portal.js.JSMain &
  echo $! > ${JSPID} ;
  chmod 640 ${JSLOG} ;
  chmod 640 ${JSPID} )

# get rc from cm startup
exit $?

