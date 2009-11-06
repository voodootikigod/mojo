
user = {
	name: 'Tj',
	roles: [
	  { name: 'Admin' },
	  { name: 'Manager' }
	]
}

function enumerate(a, fn) {
	var buf = []
	for (var i = 0, len = a.length; i < len; ++i)
	  buf.push(fn(a[i]))
	return buf.join(' ')
}

function render(o) {
  return '<div>\n\
	  <h2>' + (o.name) + '</h2>\n\
	  <ul>\n\
	    \n\
	    ' + enumerate(o.roles, function(o){
	    return '\n\
	      <li>' + (o.name) + '</li>\n\
	    '}) + '\n\
	    \n\
	    ' + enumerate(o.roles, function(o){
	    return '\n\
	      <li>' + (o.name) + '</li>\n\
	    '}) + '\n\
	  </ul>\n\
	</div>\n\
	\n\
	'
}

print(render(user))