var strResult = '';
var cutoff = '';
var startdate = '';
var start = '';
var end = '';
var lRsrcID = ly.GetInput('rsrcid');


ly.log("RSRCID: " + lRsrcID);
var strSQLm = "select top 1 convert(varchar, attr1val, 102) cut from codeattribute where catcd = 100022 and delflg = 0 order by itmcd desc";

var querym = ly.CreateQuery(strSQLm);
var rsm = querym.GetCursor();

if(!rsm.EOF)
{
  cutoff= rsm("cut");
}

var d2 = new Date(cutoff);

ly.log("cutoff: " +cutoff);
ly.log("D2: " +d2);

//var rs = ly.ExecuteSQL('select  convert(varchar, date4, 101) as date4 from personoptional1 where personfk = ' + lRsrcID);
var strsql = "select convert(varchar, date4, 101) as date4 from personoptional1 where personfk = "+lRsrcID+"";
var query = ly.CreateQuery(strsql);
var rs = query.GetCursor();

if (!rs.EOF){
   startdate = rs("date4");
}
var d1 = new Date(startdate);

ly.log("startdate - date4: " +startdate);
ly.log("D1 - date4: " +d1);

if(d1 > d2){
start = startdate;
}
else
{
start = cutoff;
}


var cutoff1 = '';
var startdate1 = '';


var strSQLm1 = "select top 1 convert(varchar, attr2val, 102) cut from codeattribute where catcd = 100022 and delflg = 0 order by itmcd desc";

var querym1 = ly.CreateQuery(strSQLm1);
var rsm1 = querym1.GetCursor();

if(!rsm1.EOF)
{
  cutoff1= rsm1("cut");
}

var d21 = new Date(cutoff1);

ly.log("cutoff1: " +cutoff1);
ly.log("D21: " +d21);

//var rs1 = ly.ExecuteSQL('select convert(varchar, custom55dt, 101) as custom55dt from resume3 where rsrcid = ' + lRsrcID);
var strsql1 = "select  convert(varchar, date5, 101) as date5 from personoptional1 where personfk = " +lRsrcID+"";
var query1 = ly.CreateQuery(strsql1);
var rs1 = query1.GetCursor();

if (!rs1.EOF){
   startdate1 = rs1("date5");
}
var d11 = new Date(startdate1);

ly.log("startdate1 - date5: " +startdate1);
ly.log("D11 - date5: " +d11);

if(d11 > d21){
end = startdate1;
}
else
{
end = cutoff1;
}

var Ad1 = new Date(start);
var Ad2 = new Date(end);

var oneDay = 24*60*60*1000; // hours*minutes*seconds*milliseconds

var diffDays = Math.round(Math.abs((Ad2.getTime() - Ad1.getTime())/(oneDay)));

strResult = diffDays;

strResult;