//UPDATE Post-Adjustment
var textPA = [];
var textDSA = [];
var textHC = [];
var textRR = [];

var updateAll = function(d){
    d3.select("#currSelectedCountry").html(d.name);
//    d3.select("#accordion").style("opacity",1)

    //Delete content rows from all tables
    if(textPA.length>0){
        textPA.forEach(function(){
            document.getElementById("tbodyPA").deleteRow(0);
        });
    };
    if(textDSA.length>0){
        textDSA.forEach(function(){
            document.getElementById("tbodyDSA").deleteRow(0);
        });
    };
    if(textHC.length>0){
        textHC.forEach(function(){
            document.getElementById("tbodyHC").deleteRow(0);
        });
    };
    if(textRR.length>0){
        textRR.forEach(function(){
            document.getElementById("tbodyRR").deleteRow(0);
        });
    };


    //empty arrays
    textPA=[];
    textDSA=[];
    textHC=[];
    textRR = [];

    updatePA(d);
    updateDSA(d);
    updateRR(d);
    updateHC(d);
};


var updatePA = function(d){

    if(document.getElementById("alertPA")){
        var element = document.getElementById("alertPA");
        element.parentNode.removeChild(element);
    }
    //Get values for PA update
    dataPA.forEach(function (p) { //for each post-adjustment object...
        if (p.id == d.id) {
            textPA.push(
                {   "eff_date": p.eff_date,
                    "exch": p.exch,
                    "originalcount": p.originalcount,
                    "Index": p.Index,
                    "Multiplier": p.Multiplier,
                    "dep": p.dep + "%",
                    "sing": p.sing + "%",
                    "t_eff_date": p.t_eff_date
                });
        };

    });
    if(textPA.length === 0){
        var noDataPA = "No post adjustment data is available for " + d.name + ".";

        var node=document.createElement("div");
        var textnode=document.createTextNode(noDataPA);
        node.appendChild(textnode);

        document.getElementById("PA").appendChild(node).setAttribute("id", "alertPA");
        document.getElementById("tablePA").style.display = "none";
        document.getElementById("sourcePA").style.display = "none";

    } else{
        document.getElementById("tablePA").style.display = "block";
        textPA.forEach(function(d,i){
            var tbody = document.getElementById("tbodyPA");
            var row = tbody.insertRow(0);
            var cell1 = row.insertCell(0);
            var cell2 = row.insertCell(1);
            var cell3 = row.insertCell(2);
            var cell4 = row.insertCell(3);
            var cell5 = row.insertCell(4);
            var cell6 = row.insertCell(5);
            var cell7 = row.insertCell(6);
            cell1.innerHTML = d.originalcount;
            cell2.innerHTML = d.exch;
            cell3.innerHTML = d.Index;
            cell4.innerHTML = d.Multiplier;
            cell5.innerHTML = d.dep;
            cell6.innerHTML = d.sing;
            cell7.innerHTML = d.t_eff_date;
        });
        document.getElementById("sourcePA").style.display="block";
        document.getElementById("sourcePA").innerHTML = "<p class='source'>Source: <a href='http://icsc.un.org/secretariat/cold.asp?include=par' target='_blank'>http://icsc.un.org/secretariat/cold.asp?include=par</a></p>";
    }

};

var updateDSA = function(d){
    if(document.getElementById("alertDSA")){
        var element = document.getElementById("alertDSA");
        element.parentNode.removeChild(element);
    }

    dataDSA.forEach(function (p) { //for each DSA object...
        if (p.id == d.id) {
            textDSA.push(
                {   "country": p.country,
                    "currency": p.currency,
                    "area": p.area,
                    "usd": p.usd,
                    "loc": p.loc,
                    "locplus": p.locplus,
                    "roompercent": p.roompercent + "%",
                    "effdate": p.effdate
                });
        }
    });

    if (textDSA.length === 0) {
        var noDataDSA = "No daily subsistence allowance data is available for " + d.name + ".";

        var node = document.createElement("div");
        var textnode = document.createTextNode(noDataDSA);
        node.appendChild(textnode);

        document.getElementById("DSA").appendChild(node).setAttribute("id", "alertDSA");
        document.getElementById("tableDSA").style.display = "none";
        document.getElementById("sourceDSA").style.display = "none";

    } else {
        document.getElementById("tableDSA").style.display = "block";
        textDSA.forEach(function (d, i) {
            var tbody = document.getElementById("tbodyDSA");
            var row = tbody.insertRow(0);
            var cell1 = row.insertCell(0);
            var cell2 = row.insertCell(1);
            var cell3 = row.insertCell(2);
            var cell4 = row.insertCell(3);
            var cell5 = row.insertCell(4);
            var cell6 = row.insertCell(5);
            var cell7 = row.insertCell(6);
            var cell8 = row.insertCell(7);
            cell1.innerHTML = d.country;
            cell2.innerHTML = d.area;
            cell3.innerHTML = d.currency;
            cell4.innerHTML = d.usd.toLocaleString();
            cell5.innerHTML = d.loc.toLocaleString();
            cell6.innerHTML = d.locplus.toLocaleString();
            cell7.innerHTML = d.roompercent;
            cell8.innerHTML = d.effdate;
        });
        document.getElementById("sourceDSA").style.display="block";
        document.getElementById("sourceDSA").innerHTML = "<p class='source'>Source: <a href='http://icsc.un.org/secretariat/sad.asp?include=dsa' target='_blank'>http://icsc.un.org/secretariat/sad.asp?include=dsa</a></p>";
    }
};

var updateHC = function(d){
    if(document.getElementById("alertHC")){
        var element = document.getElementById("alertHC");
        element.parentNode.removeChild(element);
    }

    dataHC.forEach(function (p) {
        if(p.id == d.id) {
            textHC.push(
                {   "Country": p.Country,
                    "Area": p.Area,
                    "EFF_DATE": p.EFF_DATE,
                    "Class": p.Class
                });
        }
    });
    if (textHC.length === 0) {
        var noDataHC = "No hardship classification data is available for " + d.name + ".";

        var node = document.createElement("div");
        var textnode = document.createTextNode(noDataHC);
        node.appendChild(textnode);

        document.getElementById("HC").appendChild(node).setAttribute("id", "alertHC");
        document.getElementById("tableHC").style.display = "none";
        document.getElementById("sourceHC").style.display = "none";

    } else {
        textHC.forEach(function (d, i) {
            document.getElementById("tableHC").style.display = "block";
            var tbody = document.getElementById("tbodyHC");
            var row = tbody.insertRow(0);
            var cell1 = row.insertCell(0);
            var cell2 = row.insertCell(1);
            var cell3 = row.insertCell(2);
            cell1.innerHTML = d.Area;
            cell2.innerHTML = d.EFF_DATE;
            cell3.innerHTML = d.Class;
        });
        document.getElementById("sourceHC").style.display="block";
        document.getElementById("sourceHC").innerHTML = "<p class='source'>Source: <a href='http://icsc.un.org/secretariat/hrpd.asp?include=mah' target='_blank'>http://icsc.un.org/secretariat/hrpd.asp?include=mah</a></p>";
    }
};

var updateRR = function(d){
    if(document.getElementById("alertRR")){
        var element = document.getElementById("alertRR");
        element.parentNode.removeChild(element);
    }

    dataRR.forEach(function (p) {
        if (p.id == d.id) {
            textRR.push(
                {   "country": p.country,
                    "area": p.area,
                    "freq": p.freq,
                    "destination": p.destination
                });
        }
    });

    if (textRR.length === 0) {
        var noDataRR = "No rest & recuperation benefit is offered in " + d.name + ".";

        var node = document.createElement("div");
        var textnode = document.createTextNode(noDataRR);
        node.appendChild(textnode);

        document.getElementById("RR").appendChild(node).setAttribute("id", "alertRR");
        document.getElementById("tableRR").style.display = "none";
        document.getElementById("sourceRR").style.display = "none";

    } else {
        textRR.forEach(function (d, i) {
            document.getElementById("tableRR").style.display = "block";
            var tbody = document.getElementById("tbodyRR");
            var row = tbody.insertRow(0);
            var cell1 = row.insertCell(0);
            var cell2 = row.insertCell(1);
            var cell3 = row.insertCell(2);
            var cell4 = row.insertCell(3);
            cell1.innerHTML = d.country;
            cell2.innerHTML = d.area;
            cell3.innerHTML = d.freq;
            cell4.innerHTML = d.destination;
        });
        document.getElementById("sourceRR").style.display="block";
        document.getElementById("sourceRR").innerHTML = "<p class='source'>Source: <a href='http://www.un.org/Depts/OHRM/salaries_allowances/allowances/orb.htm' target='_blank'>http://www.un.org/Depts/OHRM/salaries_allowances/allowances/orb.htm</a></p>";
    }
};