
describe 'Mojo'
  describe '.version'
    it 'should be a triple'
      Mojo.version.should.match(/^\d+\.\d+\.\d+$/)
    end
  end

	describe '.enumerate()'
	  it 'should iterate an array returning a string'
	    var roles = [{ name: 'Admin' }, { name: 'Manager' }]
			var value = Mojo.enumerate(roles, function(role){
				return '<li>' + role.name + '</li>'
			})
			value.should.include('<li>Admin</li>')
			value.should.include('<li>Manager</li>')
	  end  
	end
	
  describe '{ name }'
    it 'should buffer the given property name'
			var s = render('article', { title: 'Mojo', body: 'Is awesome' })
			s.should.include('<div class="article">')
			s.should.include('<h2>Mojo</h2>')
			s.should.include('<p>Is awesome</p>')
			s.should.include('</div>')
    end
  end

  describe '{# name } {/ name }'
    it 'should iterate and buffer enums'
			var tj = { name: 'Tj', age: 22 }
			var joe = { name: 'Joe', age: 18 }
      var s = render('users', { users: [tj, joe] })
			s.should.include('<ul>')
			s.should.include('<li>Tj is 22</li>')
			s.should.include('<li>Joe is 18</li>')
			s.should.include('</ul>')
    end
  end
end