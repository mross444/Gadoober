var strResult = '';
var cutoff = '';
var startdate = '';
var start = '';
var end = '';
var lRsrcID = ly.GetInput('rsrcid');
var pro = [Calculated Proration % - Position 1];

if(pro < 1)
{
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

//var rs = ly.ExecuteSQL('select convert(varchar, custom55dt, 101) as custom55 from resume3 where rsrcid = ' + lRsrcID);
var rs1 = ly.CreateQuery('select convert(varchar, Date5, 101) as custom55 from PersonOptional1 where personfk = ' + lRsrcID);
var rs = rs1.GetCursor();
if (!rs.EOF){
   startdate = rs("custom55");
}
var d1 = new Date(startdate);

ly.log("startdate: " +startdate);
ly.log("D1: " +d1);

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
// MJR CHANGES 6-21-17 -- Add one day to end date, customer wants End Date to be 12/31/17 and difference to still calculate to 365
d21.setDate(d21.getDate() + 1);
// END CHANGES

ly.log("cutoff1: " +cutoff1);
ly.log("D21: " +d21);

//var rs1 = ly.ExecuteSQL('select convert(varchar, custom54dt, 101) as custom54 from resume3 where rsrcid = ' + lRsrcID);
var rs = ly.CreateQuery('select convert(varchar, Date4, 101) as custom54 from PersonOptional1 where personfk = ' + lRsrcID);
var rs1 = rs.GetCursor();

if (!rs1.EOF){
   startdate1 = rs1("custom54");
}
var d11 = new Date(startdate1);

ly.log("startdate1: " +startdate1);
ly.log("D11: " +d11);

if(d11 < d21){
end = startdate1;
}
else
{
end = cutoff1;
}

var Ad1 = new Date(start);
// MJR CHANGES 6-21-17 -- use d21 if FY End Date is the maximum
if(d11 < d21){
	var Ad2 = new Date(end);
}
else
{
	var Ad2 = d21;
}
// END CHANGES

var oneDay = 24*60*60*1000; // hours*minutes*seconds*milliseconds

var diffDays = Math.round(Math.abs((Ad2.getTime() - Ad1.getTime())/(oneDay)));

strResult = diffDays;
}
strResult;