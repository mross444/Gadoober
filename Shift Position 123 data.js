//-------------------------------------------------------------------------------
 //Shift data for Position 1/2/3
 
 // Get the resource object to validate

 
 var personpk=0;
 var strSQL="select personpk from person where  ModifiedBy='tmbatchimportuser' and DATEDIFF(day,modifieddate,getdate()) <=1";
  var qrypersons = ly.CreateQuery(strSQL);
 var rsPersons = qrypersons.Execute();

 while (!rsPersons.EOF)
	{
	personpk = rsPersons("personpk");

 //Retrieve data from "Staging Slot" (i.e. what was most recently loaded via Employee Import)
  var strSTI_ELIG_DATE = "";
  var strSTI_ELIG_DATE1 = "";
var  StagingSlotSQL= "select date3,date4 from personoptional1 p1 where personfk="+personpk;

 var qryOrgs = ly.CreateQuery(StagingSlotSQL);
 var rsOrgs = qryOrgs.Execute();

if(!rsOrgs.EOF)
	{
	strSTI_ELIG_DATE = rsOrgs("date3");
	strSTI_ELIG_DATE1 = rsOrgs("date4");

	}
if(Date.parse(strSTI_ELIG_DATE) != Date.parse(strSTI_ELIG_DATE1))
  {

//Getting hierarchylevel data 

var  strSQL= "select o.Code as hierarchylvl0 from organization o inner join organizationlang ol on o.organizationpK = ol.organizationfk where organizationpk in(SELECT oh2.actid FROM orgdomainhierarchy oh1, orgdomainhierarchy oh2 WHERE oh1.lft >= oh2.lft AND oh1.lft <= oh2.rgt AND oh1.actid in (select OrganizationFK from PersonOrganization po inner join Organization o on o.OrganizationPK = po.OrganizationFK inner join Hierarchy h on o.HierarchyFK = h.HierarchyPK where personfk ="+personpk+" and hierarchylevel=4 and MainOrganization=1)) and LevelVal =1 and LangFK =1";

 var qryOrgs5 = ly.CreateQuery(strSQL);
 var rsOrgs5 = qryOrgs5.Execute();
 var strOPERATING_GROUP = '';
 if(!rsOrgs5.EOF)
	 strOPERATING_GROUP=rsOrgs5("hierarchylvl0");
  //Getting hierarchylevel data 

strSQL= "select o.Code as hierarchylvl2 from organization o inner join organizationlang ol on o.organizationpK = ol.organizationfk where organizationpk in(SELECT oh2.actid FROM orgdomainhierarchy oh1, orgdomainhierarchy oh2 WHERE oh1.lft >= oh2.lft AND oh1.lft <= oh2.rgt AND oh1.actid in(select OrganizationFK from PersonOrganization po inner join Organization o on o.OrganizationPK = po.OrganizationFK inner join Hierarchy h on o.HierarchyFK = h.HierarchyPK where personfk ="+personpk+" and hierarchylevel=4 and MainOrganization=1)) and LevelVal =3 and LangFK =1";

 var qryOrgs1 = ly.CreateQuery(strSQL);
 var rsOrgs1 = qryOrgs1.Execute();
 var strDIVISION = '';
 if(!rsOrgs1.EOF)
	 strDIVISION=rsOrgs1("hierarchylvl2");

    //Getting hierarchylevel data 

strSQL= "select o.Code as hierarchylvl4 from organization o inner join organizationlang ol on o.organizationpK = ol.organizationfk where organizationpk in(SELECT oh2.actid FROM orgdomainhierarchy oh1, orgdomainhierarchy oh2 WHERE oh1.lft >= oh2.lft AND oh1.lft <= oh2.rgt AND oh1.actid in(select OrganizationFK from PersonOrganization po inner join Organization o on o.OrganizationPK = po.OrganizationFK inner join Hierarchy h on o.HierarchyFK = h.HierarchyPK where personfk ="+personpk+" and hierarchylevel=4 and MainOrganization=1)) and LevelVal =5 and LangFK =1";

 var qryOrgs2 = ly.CreateQuery(strSQL);
 var rsOrgs2 = qryOrgs2.Execute();
 var strSUBBUSINESS_UNIT = '';
 if(!rsOrgs2.EOF)
	 strSUBBUSINESS_UNIT=rsOrgs2("hierarchylvl4");
 
 //Note that any data currently in Slot 3 will be overwritten
   
   //Slot 2 to Slot 3
    //Retrieve data in Slot 2:
	var STRSQL2="select Date5 as custom55dt,Decimal3 as custom60num,Text31 as custom29txt,Text46 as custom44cd,Text40 as custom38txt,Text43 as custom41txt,Text37 as custom35txt  from personoptional1 po1 inner join personoptional2 po2 on po1.personfk=po2.personfk  inner join personoptional3 po3 on po1.personfk=po3.personfk where po1.personfk="+personpk;
	var qryOrgs3 = ly.CreateQuery(STRSQL2);
 var rsOrgs3 = qryOrgs3.Execute();
	var strSTI_ELIG_DATE2 = '';
     var strSTI_TARG_PERCENT2 ='';
     var strBAND_TITLE2 = '';
     var strOPERATING_GROUP2 = '';
     var strDIVISION2 = '';
     var strSUBBUSINESS_UNIT2 = '';
     var strREGION2 = '';
 if(!rsOrgs3.EOF)
 {
	 strSTI_ELIG_DATE2=rsOrgs3("custom55dt");
	 strSTI_TARG_PERCENT2=rsOrgs3("custom60num");
	 strBAND_TITLE2=rsOrgs3("custom29txt");
	 strOPERATING_GROUP2=rsOrgs3("custom44cd");
	 strDIVISION2=rsOrgs3("custom38txt");
	 strSUBBUSINESS_UNIT2=rsOrgs3("custom41txt");
	 strREGION2=rsOrgs3("custom35txt");
 }
 
 //Update Slot 3 with Slot 2 data:
  	 var UpdateSQL2="update personoptional1 set Decimal4='"+strSTI_TARG_PERCENT2+"' where personfk="+personpk;
	  var qry2to3 = ly.CreateQuery(UpdateSQL2);
       var rs2to3 = qry2to3.Execute();
  UpdateSQL2="update personoptional2 set Date6='"+strSTI_ELIG_DATE2+"',Text32='"+strBAND_TITLE2+"',Text38='"+strREGION2+"' where personfk="+personpk;
  var qry2to3_1 = ly.CreateQuery(UpdateSQL2);
       var rs2to3_1 = qry2to3_1.Execute();
  UpdateSQL2="update personoptional3 set Text47='"+strOPERATING_GROUP2+"',Text41='"+strDIVISION2+"',Text44='"+strSUBBUSINESS_UNIT2+"' where personfk="+personpk;
    var qry2to3_2 = ly.CreateQuery(UpdateSQL2);
       var rs2to3_2 = qry2to3_2.Execute();
	 
 
 
 
 //Slot 1 to Slot 2
    //Retrieve data in Slot 1:
	
	var STRSQL3="select Decimal2 as custom59num,Text30 as custom28txt,Text45 as custom43cd,Text39 as custom37txt,Text42 as custom40txt,Text36 as custom34txt from personoptional1 po1 inner join personoptional2 po2 on po1.personfk=po2.personfk  inner join personoptional3 po3 on po1.personfk=po3.personfk where po1.personfk="+personpk;
	var qryOrgs4 = ly.CreateQuery(STRSQL3);
 var rsOrgs4 = qryOrgs4.Execute();
   var strSTI_TARG_PERCENT1 = '';
	  var strBAND_TITLE1 = '';
	  var strOPERATING_GROUP1 ='';
	  var strDIVISION1 = '';
	   var strSUBBUSINESS_UNIT1 = '';
	   var strREGION1 = '';
	if(!rsOrgs4.EOF)
	{
	  strSTI_TARG_PERCENT1=rsOrgs4("custom59num");
	  strBAND_TITLE1=rsOrgs4("custom28txt");
	  strOPERATING_GROUP1=rsOrgs4("custom43cd");
	  strDIVISION1 =rsOrgs4("custom37txt");
	  strSUBBUSINESS_UNIT1 =rsOrgs4("custom40txt");
	  strREGION1 =rsOrgs4("custom34txt");
	}
	
	//Update Slot 2 with Slot 1 data:
	var UpdateSQL3="update personoptional1 set Date5='"+strSTI_ELIG_DATE1+"', Decimal3='"+strSTI_TARG_PERCENT1+"' where personfk="+personpk;
	var qry1to2 = ly.CreateQuery(UpdateSQL3);
    var rs1to2 = qry1to2.Execute();
	UpdateSQL3="update personoptional2 set Text31='"+strBAND_TITLE1+"',Text40='"+strDIVISION1+"',Text37='"+strREGION1+"' where personfk="+personpk;
	var qry1to2_1 = ly.CreateQuery(UpdateSQL3);
    var rs1to2_1 = qry1to2_1.Execute();
	UpdateSQL3="update personoptional3 set Text46='"+strOPERATING_GROUP1+"',Text43='"+strSUBBUSINESS_UNIT1+"' where personfk="+personpk;
	var qry1to2_2 = ly.CreateQuery(UpdateSQL3);
    var rs1to2_2 = qry1to2_2.Execute();
	
	
	//Stage Slot to Slot 1
    //Retrieve data in Stage Slot:
	var STRSQL4="select Decimal1 as custom58num,Text29 as custom27txt,RegionCode as regioncd from personoptional1 po1 inner join personoptional2 po2 on po1.personfk=po2.personfk  inner join persontm pt on po1.personfk=pt.personfk where po1.personfk="+personpk;
	var qryOrgs5 = ly.CreateQuery(STRSQL4);
	var rsOrgs5 = qryOrgs5.Execute();
	var strSTI_TARG_PERCENT = '';
     var strBAND_TITLE = '';
	 var strREGION = '';
	if(!rsOrgs5.EOF)
	{
	   strSTI_TARG_PERCENT=	rsOrgs5("custom58num");
	   strBAND_TITLE =rsOrgs5("custom27txt");
	   strREGION =rsOrgs5("regioncd");
	 
	}
	//Update Slot 1 with Stage Slot data:
     	 
	 var UpdateSQL4="update personoptional1 set Date4='"+strSTI_ELIG_DATE+"', Decimal2='"+strSTI_TARG_PERCENT+"' where personfk="+personpk;
	 var qrySto1 = ly.CreateQuery(UpdateSQL4);
    var rsSto1 = qrySto1.Execute();
	
	UpdateSQL4="update personoptional2 set Text30='"+strBAND_TITLE+"',Text39='"+strDIVISION+"',Text36='"+strREGION+"' where personfk="+personpk;
	var qrySto1_1 = ly.CreateQuery(UpdateSQL4);
    var rsSto1_1 = qrySto1_1.Execute();
	
	UpdateSQL4="update personoptional3 set Text45='"+strOPERATING_GROUP+"',Text42='"+strSUBBUSINESS_UNIT+"' where personfk="+personpk;
	var qrySto1_2 = ly.CreateQuery(UpdateSQL4);
    var rsSto1_2 = qrySto1_2.Execute();
	
 	
	}
	rsPersons.MoveNext();
	}
	
	 
     
   //END OF DATA SHIFTING
  
 
 //-------------------------------------------------------------------------------
 
 // END: Custom Logic for AMETEK