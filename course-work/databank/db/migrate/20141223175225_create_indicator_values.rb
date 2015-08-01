class CreateIndicatorValues < ActiveRecord::Migration
  def change
    create_table :indicator_values do |t|
      t.references :country, index: true
      t.references :indicator, index: true
      t.float :value
      t.datetime :measure_datetime

      t.timestamps
    end
  end
end
