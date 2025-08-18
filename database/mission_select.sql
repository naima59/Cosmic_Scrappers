SELECT
    m.id AS mission_id,
    m.type AS mission_type,
    m.risk_level,
    
    e.id AS enemy_id,
    e.type AS enemy_type,
    e.behavior AS enemy_behavior,
    
    r.id AS resource_id,
    r.name AS resource_name,
    r.rarity AS resource_rarity,
	
	u.name,
	u.effect

FROM missions m
JOIN enemies e ON m.enemy_type = e.type
JOIN resources r ON e.resource_target_id = r.id 
JOIN upgrades u ON r.id = u.resource_id