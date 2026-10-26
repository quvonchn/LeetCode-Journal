/* Write your T-SQL query statement below */
with Firstorder as (
    select 
        customer_id,
        order_date,
        customer_pref_delivery_date,
        Row_number() over (partition by customer_id order by order_date ASC) as rn
    from Delivery
)
select 
    round( 100.0 * sum(case when order_date=customer_pref_delivery_date then 1 else 0  end )/count(*),2) as immediate_percentage
    from firstorder
    where rn=1 
