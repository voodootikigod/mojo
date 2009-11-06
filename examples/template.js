
load('lib/mojo.js')

function render(template, o) {
	return eval(readFile('examples/' + template + '.html.js'))
}

page = {
	title: 'Articles',
	articles: [
	  { title: 'One', body: 'some more one' },
	  { title: 'Two', body: 'some more two', published: true }
	]
}

print(render('template', page))