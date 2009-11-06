
JSpec.include({
	name: 'Mojo',
	utilities: {
		render: function(name, o) {
			return eval(JSpec.load('spec/fixtures/' + name + '.html.js'))
		}
	}
})