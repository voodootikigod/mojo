// to run: node benchmark-mustache.js
var sys = require("sys"),
	mustache = require('./mustache');

n = 5000

sys.puts('Running ' + n + ' times')

function benchmark(label, fn) {
	var start = Number(new Date)
	for (var i = 0; i < n; ++i) fn()
	sys.puts(label + ': ' + (Number(new Date) - start).toString() + 'ms')
}

var template='<html><head><title>{{title}}</title></head><body><h1>{{title}}</h1>{{#articles}}<div class="article"><h2>{{title}}</h2><p>{{body}}</p>{{#published}}<p>{{title}} is published</p></div>{{/articles}}</body></html>';

benchmark('large template', function(){
	mustache.to_html(template, {
		title: 'Articles',
		articles: [
		  { title: 'One', body: 'Some foo bar' },
		  { title: 'Two', body: 'Some foo bar' },
		  { title: 'Three', body: 'Some foo bar', published: true },
		  { title: 'Four', body: 'Some foo bar', published: true }
		]
	});
});