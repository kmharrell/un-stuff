var zoom = d3.behavior.zoom()
    .scaleExtent([1, 10])
    .on("zoom", move)
    .on("zoomend", function () {
    });

var width = 1026;
var height = width / 2.4;

var dataPA,
    dataDSA,
    dataHC,
    dataRR;

var countries;
var countryNames = [];

var topo, projection, path, svg, g;
var throttleTimer;
var currClicked;

//TOOLTIP
var tooltip = d3.select("#map")
    .append("div")
    .attr("class", "tooltip hidden");

setup(width, height);

var country;
//UI BOOTSTRAPPING

function setup(width, height) {
    projection = d3.geo.equirectangular()
        .translate([0, 0])
        .scale(width / 2.2 / Math.PI);

    path = d3.geo.path()
        .projection(projection);

    svg = d3.select("#map").append("svg")
        .attr("width", width)
        .attr("height", height)
        .append("g")
        .attr("transform", "translate(" + width / 2 + "," + height / 1.8 + ")")
        .call(zoom);

    g = svg.append("g");
}

function draw(topo) {

    country = g.selectAll(".country").data(topo);

    country.enter().append("path")
        .filter(function (d) {
            return d
        })
        .attr("id", function (d) {
            return "iso" + d.id;
        })
        .attr("class", "country")
        .attr("d", path)
        .style("fill", function (d, i) {
            return "#CCC"
        })
        .style("stroke-width", .5);

    //ofsets plus width/height of transform, plsu 20 px of padding, plus 20 extra for tooltip offset off mouse
    var offsetL = document.getElementById('map').offsetLeft + (width / 2) + 40;
    var offsetT = document.getElementById('map').offsetTop + (height / 2) + 20;
    var currHeight = tooltip.style("height").slice(0, -2);

    country
        .on("mousemove", function (d, i) {
            d3.select(this).style("fill", "#6999c9");
            var mouse = d3.mouse(svg.node()).map(function (d) {
                return parseInt(d);
            });

            tooltip
                .classed("hidden", false)
                .attr("style", "left:" + (d3.event.pageX - (tooltip.style("width").slice(0, -2) / 2 + 10)) + "px;top:" + (d3.event.pageY - currHeight - 25) + "px")
                .html(d.name);
        })
        .on("mouseover", function (d) {
            tooltip
                .classed("hidden", false)
                .attr("style", "left:" + (d3.event.pageX - (tooltip.style("width").slice(0, -2) / 2) + 10) + "px;top:" + (d3.event.pageY - currHeight - 20) + "px")
                .html(d.name);
        })
        .on("mouseout", function (d) {
            if (d3.select(this).attr("class") != "selected country") {
                d3.select(this).style("fill", "#CCC");
            }
            ;
            tooltip.classed("hidden", true);
        })
        .on("click", function (d) {
            // Find previously selected, unselect
            if (!d3.select(this).classed("selected country")) {
                d3.select(".selected").attr("class", "country").transition().duration(300).style("fill", "#ccc");
            }
            // Select current item
            d3.select(this).attr("class", "selected country").style("fill", "#6999c9");
            updateAll(d);
        });

    g.selectAll(".jerusalem").data(topo).enter()
        .append('svg:circle')
        .filter(function (d) {
            return d.name === "Jerusalem"
        })
        .attr("class", "jerusalem")
        .attr('cx', function (d) {
            return 91
        })
        .attr('cy', function () {
            return -82.5
        })
        .attr('r', .5)
        .style("fill", "#ccc")
        .style("stroke-width", .1)
        .style("stroke", "white")
        .on("mousemove", function (d) {
            d3.select(this).style("fill", "#6999c9")
            var mouse = d3.mouse(svg.node()).map(function (d) {
                return parseInt(d);
            });
            tooltip
                .classed("hidden", false)
                .attr("style", "left:" + (d3.event.pageX - (tooltip.style("width").slice(0, -2) / 2 + 10)) + "px;top:" + (d3.event.pageY - currHeight - 25) + "px")
                .html(d.name);

        })
        .on("mouseover", function (d) {
            console.log(d);
            tooltip
                .classed("hidden", false)
                .attr("style", "left:" + (d3.event.pageX - (tooltip.style("width").slice(0, -2) / 2) + 10) + "px;top:" + (d3.event.pageY - currHeight - 20) + "px")
                .html(d.name);

        })
        .on("mouseout", function (d) {
            if (d3.select(this).attr("class") != "selected jerusalem") {
                d3.select(this).style("fill", "#CCC");
            }
            tooltip.classed("hidden", true);
        })
        .on("click", function (d) {

            if (!d3.select(this).classed("selected jerusalem")) {
                console.log("hi");
                // Find previously selected, unselect
                d3.select(".selected").attr("class", "jerusalem").transition().duration(300).style("fill", "#ccc");
            }
            // Select current item
            console.log(this);
            d3.select(this).attr("class", "selected jerusalem").style("fill", "#6999c9");
            updateAll(d);
        });
}

function redraw() {
    width = document.getElementById('map').offsetWidth - 60;
    height = width / 2;
    d3.select('svg').remove();
    setup(width, height);
    draw(topo);
}

function move(type) {
    var s;
    var increment = .5;
    var maxIn = zoom.scaleExtent()[1] - increment;
    var maxOut = zoom.scaleExtent()[0] + increment;

    if (type == "zoomin" && zoom.scale() <= maxIn) {
        s = zoom.scale() + increment;
        zoom.scale(s);
        console.log(s);
    } else if (type == "zoomout" && zoom.scale() >= maxOut) {
        s = zoom.scale() - increment;
        zoom.scale(s);
        console.log(s);
    } else {
        //just mouse zoom
        s = zoom.scale();
    }

    var t = zoom.translate();
    var h = 0;

    t[0] = Math.min(width / 2 * (s - 1), Math.max(width / 2 * (1 - s), t[0]));
    t[1] = Math.min(height / 2 * (s - 1) + h * s, Math.max(height / 2 * (1 - s) - h * s, t[1]));

    zoom.translate(t);

    if (type) {
        g.transition().duration(500).attr("transform", "translate(" + t + ")scale(" + s + ")");
    } else {
        g.attr("transform", "translate(" + t + ")scale(" + s + ")");
    }

    g.selectAll(".country").data(countries).style("stroke-width", 0.5 / s);

}

//ACCORDION CONTENT
$("#accordion").accordion(
    {active: 0,
        heightStyle: "content"
    }
)
    .accordion({
        activate: function (event, ui) {
        }
    });

//Get Active Accordion
var active = $("#accordion").accordion("option", "active");
var heightStyle = $(".selector").accordion("option", "heightStyle");

//ZOOM BUTTONS
$(function () {
    $("input[type=submit], button")
        .button()
        .click(function (event) {
            event.preventDefault();
        });
});

var zoomBox = d3.select("#map").append("div").attr("class", "zoomBox");
zoomBox.append("button").attr("class", "button").attr("id", "zoomin").text("﹢");
zoomBox.append("button").attr("class", "button").attr("id", "zoomout").text("─");

d3.select("#zoomin").on("click", function (d, i) {
    move("zoomin");
});
d3.select("#zoomout").on("click", function (d, i) {
    move("zoomout");
});