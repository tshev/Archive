class Country < ActiveRecord::Base
  has_many :indicator_values
end
