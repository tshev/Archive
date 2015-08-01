class CreateIndicatorRelations < ActiveRecord::Migration
  def change
    create_table :indicator_relations do |t|
      t.integer :parent_indicator_id
      t.integer :child_indicator_id

      t.timestamps
    end
  end
end
