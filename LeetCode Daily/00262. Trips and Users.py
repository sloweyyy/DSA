import pandas as pd
def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    valid = users.loc[users["banned"].eq("No"), "users_id"]
    selected = trips[trips["client_id"].isin(valid) & trips["driver_id"].isin(valid) & trips["request_at"].between("2013-10-01", "2013-10-03")]
    grouped = selected.assign(cancelled=selected["status"].ne("completed")).groupby("request_at")["cancelled"].agg(["sum", "count"]).reset_index()
    grouped["Cancellation Rate"] = ((200 * grouped["sum"] + grouped["count"]) // (2 * grouped["count"])) / 100
    return grouped.rename(columns={"request_at": "Day"})[["Day", "Cancellation Rate"]]
