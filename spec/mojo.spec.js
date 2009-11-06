
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
      var str = fixture('article')
			print(str)
    end
  end
end