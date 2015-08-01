from model.speak import *
def get():
	s = """<!DOCTYPE html><html><head>
		<style>
			.fixed {
				position: fixed;
				width: inherit;
				right: auto;
			}
			body {
			color: #44;	
			font-family: Serif;
			margin: 0;
			background:url("http://nerdreactor.com/wp-content/uploads/2014/05/19c0uzmi9bmv1jpg.jpg");
			background-position: fixed;
			}
			a {
				color: #2372FA;
				font-size: 1.1em;
			}
		table > thead { background: #fff;}
			td { border-right: 2px groove rgba(0,0,230,0.01); padding-right: 15px; padding-left:10px;}
			th { border: 2px groove rgba(0,0,230,0.2); background: rgba(0,0,230,0.4); color: #fff; padding-right: 15px; padding-left:9px;}
			table{ width: 100%; padding: 2px;}
			.col-1 { width: 12%;  }
			.col-5 { width: 50%; }
			.col-4 { width: 38%; }
			tr { box-shadow: 0 10px rgba(245, 245, 245, 0.5);
			background: rgba(245,245,245,0.3);
			height: 35px;
			}
			.centered-object { width: 1284px; margin: 0 auto; background: rgba(255,255,255,0.999);diplay:block; padding: 10px; padding-top:0;
	display: table;	
	}
		.block {
			float: left;
			display: block;
			padding: 10px;
			padding-top: 0;
		}
		.panel {
			width: 290px;
			margin: 0 auto;
			background: #eee;
			padding: 5px;
			box-shadow: 1px 1px rgba(0,0,230,0.4);
			
		}
		.col-md-4 {
			width: 28%;
		}
		.col-md-16 {
			width: 68%;
		}
		.panel {
		margin-bottom: 10px;
		overflow-y: scroll;
		max-height: 300px;
		padding-left:10px;
		}
		.btn {
			border-radius: 2px;
			padding: 6px;
			text-decoration:none;
			margin: 2px;
		}
		.btn-primary {
			color: #fff;
			background: #2372FA;
		}
		.list-unstyled {
			list-style-type: none;
			margin-left: -35px;
			display: block;
		}
		.list-unstyled > li{
			padding: 5px;
			padding-left: 20px;
			margin-top: 2px;
			background: #fff;
			border-radius: 2px;
		}
		.list-unstyled > li > a {
			text-decoration:none;
		}
		input {
			padding: 4px;
		}
		</style>
	</head><body>
	"""
	s += "<div class=\"centered-object\"><div class=\"block col-md-16\"><table style=\"margin-top:-4px;position:fixed; width:878px;top:0px;text-align:left;\"><thead><th class=\"col-1\">Rank</th><th class=\"col-5\">Movie</th><th class=\"col-4\">Ganre</th></thead></table><table><br/><br/>"
	r = list(selectFilms())
	r = sorted(r,key=lambda x: x[0])
	#print r[0][0]
	#print "*"*1000
	for i in r:
		s += "<tr><td class=\"col-1\">%d</td><td class=\"col-5\">%s</td><td class=\"col-4\"><a href=\"#\">%s</a></td></tr>"%(i[0], i[1], i[2])
	s += "</table></div>" +"""
	<div class="block col-md-4">
		
		<br/>
		<br/>
		<div class="fixed">
		<div class="panel">
			<h3>Search your favourite film</h3>
			<input type="text" placeholder="search" /><a href="#" class="btn btn-primary">Find</a>
		</div>
		<div class="panel">
		<h3>Жанры</h3>
		<ul class="list-unstyled">
			<li><a href="#">First</a></li>
			<li><a href="#">First</a></li>
			<li><a href="#">First</a></li>
			<li><a href="#">First</a></li>
			<li><a href="#">First</a></li>
			<li><a href="#">First</a></li>
		</ul>
		</div>
		</div>
	</div>
  </div></body></html>"""
	return s
