d3.json("data/readme-world.json", function (world) {
    d3.json("data/iso.json", function (iso) {
        d3.json("data/dictionary.json", function (dic) {
            var starttime = new Date().getMilliseconds();

            //LOAD DATA
            d3.json("data/rnr.json", function (data) {
                dataRR = data;
            });
            d3.json("data/hc.json", function (d) {
                var starttime = new Date().getMilliseconds();
                var predataHC = d.HARDSHIP_XML;

                predataHC.forEach(function(e){

                    //HACK: Data is missing e.Country value for Laayoune
                    if (e.Area == "Laayoune"){
                        e.Country = "Western Sahara";
                    }

                    //RENAME COUNTRIES
                    dic.forEach(function (dictionary) {
                        if (e.Country == dictionary.name) {
                            e.Country = dictionary.correctName;
                        }
                    });

                    //ATTACH ISO ID'S
                    iso.forEach(function(p) {
                        if (e.Country === p.name) {
                            e.id = p.id;
                        }
                    })
                })

//                TEST: CHECK FOR REMAINING COUNTRIES THAT DON'T HAVE ID'S
/*                predataHC.forEach(function (dpa) {
                    if (!dpa.id) {
                        console.log(dpa)
                    }
                    else{
                        console.log("all good HC")
                    }
                });*/

                dataHC = predataHC;
                var endtime = new Date().getMilliseconds();
                console.log("HC data processing time: " + (endtime - starttime)+ "ms");
            });
            d3.json("data/pa.json", function (d) {
                var starttime = new Date().getMilliseconds();
                var predataPA = d.dataroot.dataXML_o;

                predataPA.forEach(function(e){

                    //RENAME COUNTRIES
                    dic.forEach(function (dictionary) {
                        if (e.country == dictionary.name) {
                            e.country = dictionary.correctName;
                        }
                    });

                    //ATTACH ISO ID'S
                    iso.forEach(function(p) {
                        if (e.country === p.name) {
                            e.id = p.id;
                        }
                    })


                })

//                //TEST: CHECK FOR REMAINING COUNTRIES THAT DON'T HAVE ID'S
//                predataPA.forEach(function (dpa) {
//                    if (!dpa.id) {
//                        console.log(dpa)
//                    }
//                })

                dataPA = predataPA;
                var endtime = new Date().getMilliseconds();
                console.log("PA data processing time: " + (endtime - starttime)+ "ms");
            });
            d3.json("data/dsa.json", function (d) {
                var starttime = new Date().getMilliseconds();
                var predataDSA = [];
                var Country_Collection = d.table1.Country_Collection.Country;

                //REFORMAT DATA FROM XML/JSON
                Country_Collection.forEach(function (d, i) {

                    var countryName = extractCountry(d['@attributes'].Country_Name),
                        id;

                    //RENAME COUNTRIES
                    dic.forEach(function (d) {
                        if (countryName == d.name) {
                            countryName = d.correctName;
                        }
                    });

                    //ATTACH ISO ID'S
                    iso.forEach(function (p) { // 200 long
                        if (countryName === p.name) {
                            id = p.id;
                        }
                    })

                    var countryCurrency = extractCurrency(d['@attributes'].Country_Name);
                    var Detail_Collection = d['Detail_Collection'].Detail;

                    if (Detail_Collection.length === undefined) {
                        predataDSA.push({
                            "country": countryName,
                            "currency": countryCurrency,
                            "area": Detail_Collection['@attributes'].DS_Long_Name,
                            "usd": parseInt(Detail_Collection['@attributes'].USD_Amount),
                            "loc": parseInt(Detail_Collection['@attributes'].Local_Amount1),
                            "locplus": parseInt(Detail_Collection['@attributes'].Local_Amount2),
                            "roompercent": parseInt(Detail_Collection['@attributes'].Room_Percentage),
                            "effdate": formatUTCDate(Detail_Collection['@attributes'].DSA_Eff_Date),
                            "survdate": formatUTCDate(Detail_Collection['@attributes'].Finalization_Date),
                            "id": id
                        });
                    }
                    else {
                        Detail_Collection.forEach(function (x) {
                            predataDSA.push({
                                "country": countryName,
                                "currency": countryCurrency,
                                "area": x['@attributes'].DS_Long_Name,
                                "usd": parseInt(x['@attributes'].USD_Amount),
                                "loc": parseInt(x['@attributes'].Local_Amount1),
                                "locplus": parseInt(x['@attributes'].Local_Amount2),
                                "roompercent": parseInt(x['@attributes'].Room_Percentage),
                                "effdate": formatUTCDate(x['@attributes'].DSA_Eff_Date),
                                "survdate": formatUTCDate(x['@attributes'].Finalization_Date),
                                "id": id
                            });
                        })
                    }
                })

                /*
                 //TEST: CHECK FOR REMAINING COUNTRIES THAT DON'T HAVE ID'S
                 predataDSA.forEach(function (d) {
                 if (!d.id) {
                 console.log(d)
                 }
                 })*/
                dataDSA = predataDSA;

                var endtime = new Date().getMilliseconds();
                console.log("DSA data processing time: " + (endtime - starttime)+ "ms");
            });

            /*
             d3.json("data/dsa-03.json", function (data) {
             dataDSA = data;
             });
             d3.json("data/post-adjustment.json", function (data) {
             dataPA = data;
             });
             d3.json("data/hardship-classification.json", function (data) {
             dataHC = data;
             });
             */

            d3.json("data/sp.json", function (d) {
                var starttime = new Date().getMilliseconds();
                console.log(d);
                var predataSP = [];
                var tempData = [];
                var Salary_Collection = d.table1.Detail_Collection.Detail;

                var romanNumerals = ["I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI"];
                Salary_Collection.forEach(function (d, i) {


                    ////new stuff starts here

//                    if (d['@attributes'].CATEGORY_ID.trim() == "P"){
//                        tempData.push({
//                            "category": d['@attributes'].CATEGORY_ID.trim(),
//                            "grade": d['@attributes'].GRADE_ID.trim(),
//                            "salary": parseInt(d['@attributes'].GROSS_SAL),
//                            "month": d['@attributes'].MONTH,
//                            "dep": parseInt(d['@attributes'].NET_DEPENDENT),
//                            "sing": parseInt(d['@attributes'].NET_SINGLE),
//                            "step": parseInt(d['@attributes'].STEP),
//                            //"step": romanNumerals[parseInt(d['@attributes'].STEP)-1],
//                            "year": d['@attributes'].YEAR
//                        })
//                    }
//                    tempData.sort(function(a,b){
//                        return a.grade - b.grade;
//
//                    })
//                    tempData.reverse();
//                    console.log(tempData);
//                    predataSP.push(tempData);
//                    console.log(predataSP);

                    ///end


                    predataSP.push({
                        "category": d['@attributes'].CATEGORY_ID.trim(),
                        "grade": d['@attributes'].GRADE_ID.trim(),
                        "salary": parseInt(d['@attributes'].GROSS_SAL),
                        "month": d['@attributes'].MONTH,
                        "dep": parseInt(d['@attributes'].NET_DEPENDENT),
                        "sing": parseInt(d['@attributes'].NET_SINGLE),
                        "step": parseInt(d['@attributes'].STEP),
                        //"step": romanNumerals[parseInt(d['@attributes'].STEP)-1],
                        "year": d['@attributes'].YEAR
                    });
                })

                //re-order
                predataSP.filter(function(d){return d.category =="D"}).forEach(function(d, i){
                    predataSP.push(d);
                    predataSP.splice(2,1);
                });
                predataSP.filter(function(d){return d.category =="ASG"}).forEach(function(d, i){
                    predataSP.push(d);
                    predataSP.splice(0,1);
                });
                predataSP.filter(function(d){return d.category =="USG"}).forEach(function(d, i){
                    predataSP.push(d);
                    predataSP.splice(0,1);
                });

                dataSP = predataSP;

                console.log(dataSP);

                var endtime = new Date().getMilliseconds();
                console.log("SP data processing time: " + (endtime - starttime)+ "ms");
            });

            countries = topojson.feature(world, world.objects.countries).features,
                neighbors = topojson.neighbors(world.objects.countries.geometries);

            //Push country names
            countries.forEach(function (d, i) {
                iso.forEach(function (s, i) {
                    if (d.id === s.id) {
                        d.name = s.name
                    }
                });
            });
            //Jerusalem Addition
            countries.push({"type": "Feature", "id": 999, "properties": {}, "geometry": {
                "type": "Polygon",
                "coordinates": []
            }, "name": "Jerusalem"});
            //document.write(JSON.stringify(countries[241]));

            //Associate country names on map
            countries.forEach(function (d, i) {
                if (d.name) {
                    countryNames.push(d.name)
                }
                ;
            });

            draw(countries);

            //SEARCH
            var currFocus;
            $(".search")
                .autocomplete({
                    source: countryNames,
                    focus: function (event, ui) {
                    },
                    change: function (event, ui) {
                    }
                })
                .on("autocompletefocus", function (event, ui) {
                    country.forEach(function (country) {
//                    console.dir(country[242]);
                        iso.forEach(function (d) {
                            //console.log('this is d.name: '+ d.name);
                            if (d.name == ui.item.value) {

                                // Find previously selected, unselect
                                d3.select(currFocus).style("fill", "#ccc");

                                // Select current new focus
                                currFocus = "path#iso" + d.id;
                                d3.select(currFocus).style("fill", "#6999c9");
                                console.log("focusing: " + currFocus);

                                // ".selected" is always blue
                                d3.select(".selected").style("fill", "#6999c9");
                            }
                        })
                    })
                })
                .on("autocompletechange", function (event, ui) {
                    console.log("changing" + currFocus);

                    if (!d3.select(currFocus).classed("selected country")) {
                        // Find previously selected, unselect
                        d3.select(currFocus).style("fill", "#ccc");
                    }

                    // ".selected" is always blue
                    d3.select(".selected").style("fill", "#6999c9");
                })
                .on("autocompleteselect", function (event, ui) {
                    console.log(ui.item.value);
                    console.log("SELECTING");
                    console.log(currFocus);
                    d3.select("#currSelectedCountry").text(ui.item.value);
                    g.forEach(function (country) {
                        iso.forEach(function (d) {
                            if (d.name === ui.item.value) {
                                console.log(d.name);
                                if (!d3.select(currFocus).classed("selected country")) {
                                    // Find previously selected, unselect
                                    d3.select(".selected").attr("class", "country").transition().duration(300).style("fill", "#ccc");
                                }

                                // Select current item
                                currFocus = "path#iso" + d.id;
                                d3.select(currFocus).attr("class", "selected country").style("fill", "#6999c9");

                                updateAll(d);
                            }
                        })
                    })

                });

            var endtime = new Date().getMilliseconds();
            console.log("Time to load all data = "+(endtime-starttime) +"ms");
        });
    });
});

function extractCurrency(thisCountry) {
    var currencyExtracted = '',
        rePattern = /\((.+)\)/;

    if (thisCountry != '') {
        currencyExtracted = thisCountry.match(rePattern);
        if (currencyExtracted != null) {
            if (currencyExtracted[0] == "(U.S.A) (US Dollar)") {
                currencyExtracted = "US Dollar";
                return currencyExtracted;
            } else {
                currencyExtracted = currencyExtracted[1];
                return currencyExtracted;
            }
        }
    }
    ;
};

function extractCountry(thisCountry) {
    return thisCountry.substring(0, thisCountry.indexOf('(')).trim(); //remove the white space after text
}

function formatUTCDate(dateInput) {
    var a = new Date(dateInput); // original date: 2014-05-01T00:00:00
    return a.getUTCDate() + "/" + (a.getUTCMonth() + 1) + "/" + a.getUTCFullYear(); // new date: 1/5/2014
};

function findWeirdNames(data) {
    //find countries from predataDSA that have inconsistent naming
    //used to make a dictionary
    var matches = [];
    data.forEach(function (d) {
        if (!d.id) {
            console.log(d.country);
            matches.push({
                "name": d.country,
                "correctName": ""
            })
        }
    })
    document.write(JSON.stringify(matches));
};

function findWeirdNamesAlt() {

    //find countries from predataDSA that have inconsistent naming
    //used to make a dictionary

    predataDSA.forEach(function (d) {
        if (!d.id) {
            console.log(d.country);
            matches.push({
                "name": "",
                "alternatives": [
                    {
                        "name": d.country
                    }
                ]
            })
        }
    })
    document.write(JSON.stringify(matches));
};