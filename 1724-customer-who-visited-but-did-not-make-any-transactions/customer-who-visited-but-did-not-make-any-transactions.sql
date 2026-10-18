# Write your MySQL query statement below
SELECT v.customer_id,COUNT(*) as count_no_trans
FROM Visits V 
LEFT JOIN 
Transactions T
on V.visit_id=T.visit_id
WHERE T.transaction_id IS NULL
GROUP BY customer_id;