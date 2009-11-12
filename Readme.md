
# Mojo

  Mustache template compiler for ultra-fast native language templates.
  
## Supported languages

  * JavaScript
  
## Dependencies

  * gcc (compiler)
  * [leg](http://piumarta.com/software/peg/) (parser generator)
  * [jspec](http://jspec.info) (test suite only)
  
## Benchmarks

    mojo        : 5000 times  : 0.995 seconds
    mustache    : 5000 times  : 7.059 seconds
    mustache.js : 5000 times  : 21.669 seconds

    $ make benchmarks
  
## Installation

Include *lib/mojo.js* in your application and:

    $ make
    $ make install
    
## Mojo Binary

    $ mojo < in > out
    $ mojo --help

## Running Tests

    $ make test
    
## Example

View ./examples to see the source for the
examples shown below.

examples/template.html

    <html>
      <head>
        <title>{ title }</title>
      </head>
      <body>
        <h1>{ title }</h1>
        {# articles }
          <div class="article">
            <h2>{ title }</h2>
            <p>{ body }</p>
            {# published }
              <p>{ title } is published</p>
            {/ published }
          </div>
        {/ articles }
      </body>
    </html>
    
complete template using mojo:

    $ mono < examples/template.html > examples/template.html.js
    
yields the following javascript:

    '<html>\n\
      <head>\n\
        <title>' + (Mojo.escape(Mojo.normalize(o.title))) + '</title>\n\
      </head>\n\
      <body>\n\
        <h1>' + (Mojo.escape(Mojo.normalize(o.title))) + '</h1>\n\
        ' + Mojo.enumerate(o, Mojo.normalize(o.articles), function(o){
        return '\n\
          <div class="article">\n\
            <h2>' + (Mojo.escape(Mojo.normalize(o.title))) + '</h2>\n\
            <p>' + (Mojo.escape(Mojo.normalize(o.body))) + '</p>\n\
            ' + Mojo.enumerate(o, Mojo.normalize(o.published), function(o){
        return '\n\
              <p>' + (Mojo.escape(Mojo.normalize(o.title))) + ' is published</p>\n\
            '}) + '\n\
          </div>\n\
        '}) + '\n\
      </body>\n\
    </html>'
    
example template rendering implementation:

    load('lib/mojo.js')
    
    function render(template, o) {
    	return eval(readFile('examples/' + template + '.html.js'))
    }
    
template object:

    page = {
    	title: 'Articles',
    	articles: [
    	  { title: 'One', body: 'some more one' },
    	  { title: 'Two', body: 'some more two', published: true }
    	]
    }

    print(render('template', page))
    
rendered markup output:

    <html>
      <head>
        <title>Articles</title>
      </head>
      <body>
        <h1>Articles</h1>

        <div class="article">
          <h2>One</h2>
          <p>some more one</p>
        </div>
        
        <div class="article">
          <h2>Two</h2>
          <p>some more two</p>
          <p>Two is published</p>
        </div>

      </body>
    </html>
    
The templates produced by **mojo** can be simply copy / pasted
into your application, or loaded via XMLHttpRequest, or via IO
for server side implementations. 
    
## License 

(The MIT License)

Copyright (c) 2008 - 2009 TJ Holowaychuk <tj@vision-media.ca>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.