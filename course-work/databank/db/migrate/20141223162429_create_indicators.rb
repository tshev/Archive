class CreateIndicators < ActiveRecord::Migration
  def change
    create_table :indicators do |t|
      t.string :name
      t.string :code, :unique => true

      t.timestamps
    end
  end
end
