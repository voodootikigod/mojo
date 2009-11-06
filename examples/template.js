
user = {
	name: 'Tj',
	roles: [
	  { name: 'Admin' },
	  { name: 'Manager' }
	]
}

Mojo = {
	version: '0.0.1',
	enumerate: function(a, fn) {
		for (var buf = [], i = 0, len = a.length; i < len; ++i)
		  buf.push(fn(a[i]))
		return buf.join(' ')
	}
}

function render(o) {
  return '<div>\n\
	  <h2>' + (o.name) + '</h2>\n\
	  <ul>\n\
	    \n\
	    \n\
	    ' + Mojo.enumerate(o.roles, function(o){
	    return '\n\
	      <li>' + (o.name) + '</li>\n\
	    '}) + '\n\
	  </ul>\n\
	</div>\n\
	\n\
	'
}

print(render(user))