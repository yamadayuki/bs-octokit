open WebhookTypes;

type protocol =
  | Http
  | Https;
type webhookEvent('a) = {
  id: string,
  name: string,
  payload: 'a,
  protocol,
  host: option(string),
  url: option(string),
};
type transformFn('a) = webhookEvent('a) => webhookEvent('a);
type webhookOptions('a) = {
  secret: string,
  path: option(string),
  transform: option(transformFn('a)),
};
type t;
let createWebhook: option(webhookOptions(Js.Types.obj_val)) => t;
let on_check_run:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadCheckRun) => unit)
      | `completed(webhookEvent(webhookPayloadCheckRun) => unit)
      | `created(webhookEvent(webhookPayloadCheckRun) => unit)
      | `requested_action(webhookEvent(webhookPayloadCheckRun) => unit)
      | `rerequested(webhookEvent(webhookPayloadCheckRun) => unit)
    ]
  ) =>
  unit;
let on_check_suite:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadCheckSuite) => unit)
      | `completed(webhookEvent(webhookPayloadCheckSuite) => unit)
      | `requested(webhookEvent(webhookPayloadCheckSuite) => unit)
      | `rerequested(webhookEvent(webhookPayloadCheckSuite) => unit)
    ]
  ) =>
  unit;
let on_commit_comment:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadCommitComment) => unit)
      | `created(webhookEvent(webhookPayloadCommitComment) => unit)
    ]
  ) =>
  unit;
let on_create:
  (t, [ | `all(webhookEvent(webhookPayloadCreate) => unit)]) => unit;
let on_delete:
  (t, [ | `all(webhookEvent(webhookPayloadDelete) => unit)]) => unit;
let on_deployment:
  (t, [ | `all(webhookEvent(webhookPayloadDeployment) => unit)]) => unit;
let on_deployment_status:
  (t, [ | `all(webhookEvent(webhookPayloadDeploymentStatus) => unit)]) =>
  unit;
let on_fork:
  (t, [ | `all(webhookEvent(webhookPayloadFork) => unit)]) => unit;
let on_github_app_authorization:
  (
    t,
    [ | `all(webhookEvent(webhookPayloadGithubAppAuthorization) => unit)]
  ) =>
  unit;
let on_gollum:
  (t, [ | `all(webhookEvent(webhookPayloadGollum) => unit)]) => unit;
let on_installation:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadInstallation) => unit)
      | `created(webhookEvent(webhookPayloadInstallation) => unit)
      | `deleted(webhookEvent(webhookPayloadInstallation) => unit)
    ]
  ) =>
  unit;
let on_issue_comment:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadIssueComment) => unit)
      | `created(webhookEvent(webhookPayloadIssueComment) => unit)
      | `deleted(webhookEvent(webhookPayloadIssueComment) => unit)
      | `edited(webhookEvent(webhookPayloadIssueComment) => unit)
    ]
  ) =>
  unit;
let on_issues:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadIssues) => unit)
      | `assigned(webhookEvent(webhookPayloadIssues) => unit)
      | `closed(webhookEvent(webhookPayloadIssues) => unit)
      | `deleted(webhookEvent(webhookPayloadIssues) => unit)
      | `demilestoned(webhookEvent(webhookPayloadIssues) => unit)
      | `edited(webhookEvent(webhookPayloadIssues) => unit)
      | `labeled(webhookEvent(webhookPayloadIssues) => unit)
      | `milestoned(webhookEvent(webhookPayloadIssues) => unit)
      | `opened(webhookEvent(webhookPayloadIssues) => unit)
      | `reopened(webhookEvent(webhookPayloadIssues) => unit)
      | `transferred(webhookEvent(webhookPayloadIssues) => unit)
      | `unassigned(webhookEvent(webhookPayloadIssues) => unit)
      | `unlabeled(webhookEvent(webhookPayloadIssues) => unit)
    ]
  ) =>
  unit;
let on_label:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadLabel) => unit)
      | `created(webhookEvent(webhookPayloadLabel) => unit)
      | `deleted(webhookEvent(webhookPayloadLabel) => unit)
      | `edited(webhookEvent(webhookPayloadLabel) => unit)
    ]
  ) =>
  unit;
let on_marketplace_purchase:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadMarketplacePurchase) => unit)
      | `canceled(webhookEvent(webhookPayloadMarketplacePurchase) => unit)
      | `changed(webhookEvent(webhookPayloadMarketplacePurchase) => unit)
      | `pending_change(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | `pending_change_cancelled(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | `purchased(webhookEvent(webhookPayloadMarketplacePurchase) => unit)
    ]
  ) =>
  unit;
let on_member:
  (
    t,
    [
      | `added(webhookEvent(webhookPayloadMember) => unit)
      | `all(webhookEvent(webhookPayloadMember) => unit)
      | `deleted(webhookEvent(webhookPayloadMember) => unit)
      | `edited(webhookEvent(webhookPayloadMember) => unit)
    ]
  ) =>
  unit;
let on_milestone:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadMilestone) => unit)
      | `closed(webhookEvent(webhookPayloadMilestone) => unit)
      | `created(webhookEvent(webhookPayloadMilestone) => unit)
      | `deleted(webhookEvent(webhookPayloadMilestone) => unit)
      | `edited(webhookEvent(webhookPayloadMilestone) => unit)
      | `opened(webhookEvent(webhookPayloadMilestone) => unit)
    ]
  ) =>
  unit;
let on_organization:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadOrganization) => unit)
      | `member_added(webhookEvent(webhookPayloadOrganization) => unit)
      | `member_invited(webhookEvent(webhookPayloadOrganization) => unit)
      | `member_removed(webhookEvent(webhookPayloadOrganization) => unit)
    ]
  ) =>
  unit;
let on_org_block:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadOrgBlock) => unit)
      | `blocked(webhookEvent(webhookPayloadOrgBlock) => unit)
      | `unblocked(webhookEvent(webhookPayloadOrgBlock) => unit)
    ]
  ) =>
  unit;
let on_page_build:
  (t, [ | `all(webhookEvent(webhookPayloadPageBuild) => unit)]) => unit;
let on_project_card:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadProjectCard) => unit)
      | `converted(webhookEvent(webhookPayloadProjectCard) => unit)
      | `created(webhookEvent(webhookPayloadProjectCard) => unit)
      | `deleted(webhookEvent(webhookPayloadProjectCard) => unit)
      | `edited(webhookEvent(webhookPayloadProjectCard) => unit)
      | `moved(webhookEvent(webhookPayloadProjectCard) => unit)
    ]
  ) =>
  unit;
let on_project_column:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadProjectColumn) => unit)
      | `created(webhookEvent(webhookPayloadProjectColumn) => unit)
      | `deleted(webhookEvent(webhookPayloadProjectColumn) => unit)
      | `edited(webhookEvent(webhookPayloadProjectColumn) => unit)
      | `moved(webhookEvent(webhookPayloadProjectColumn) => unit)
    ]
  ) =>
  unit;
let on_project:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadProject) => unit)
      | `closed(webhookEvent(webhookPayloadProject) => unit)
      | `created(webhookEvent(webhookPayloadProject) => unit)
      | `deleted(webhookEvent(webhookPayloadProject) => unit)
      | `edited(webhookEvent(webhookPayloadProject) => unit)
      | `reopened(webhookEvent(webhookPayloadProject) => unit)
    ]
  ) =>
  unit;
let on_public:
  (t, [ | `all(webhookEvent(webhookPayloadPublic) => unit)]) => unit;
let on_pull_request:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadPullRequest) => unit)
      | `assigned(webhookEvent(webhookPayloadPullRequest) => unit)
      | `closed(webhookEvent(webhookPayloadPullRequest) => unit)
      | `edited(webhookEvent(webhookPayloadPullRequest) => unit)
      | `labeled(webhookEvent(webhookPayloadPullRequest) => unit)
      | `openend(webhookEvent(webhookPayloadPullRequest) => unit)
      | `reopened(webhookEvent(webhookPayloadPullRequest) => unit)
      | `review_request_removed(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | `review_requested(webhookEvent(webhookPayloadPullRequest) => unit)
      | `synchronize(webhookEvent(webhookPayloadPullRequest) => unit)
      | `unassigned(webhookEvent(webhookPayloadPullRequest) => unit)
      | `unlabeled(webhookEvent(webhookPayloadPullRequest) => unit)
    ]
  ) =>
  unit;
let on_pull_request_review:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadPullRequestReview) => unit)
      | `dismissed(webhookEvent(webhookPayloadPullRequestReview) => unit)
      | `edited(webhookEvent(webhookPayloadPullRequestReview) => unit)
      | `submitted(webhookEvent(webhookPayloadPullRequestReview) => unit)
    ]
  ) =>
  unit;
let on_pull_request_review_comment:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadPullRequestReviewComment) => unit)
      | `created(
          webhookEvent(webhookPayloadPullRequestReviewComment) => unit,
        )
      | `deleted(
          webhookEvent(webhookPayloadPullRequestReviewComment) => unit,
        )
      | `edited(webhookEvent(webhookPayloadPullRequestReviewComment) => unit)
    ]
  ) =>
  unit;
let on_push:
  (t, [ | `all(webhookEvent(webhookPayloadPush) => unit)]) => unit;
let on_release:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadRelease) => unit)
      | `published(webhookEvent(webhookPayloadRelease) => unit)
    ]
  ) =>
  unit;
let on_repository:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadRepository) => unit)
      | `archived(webhookEvent(webhookPayloadRepository) => unit)
      | `created(webhookEvent(webhookPayloadRepository) => unit)
      | `deleted(webhookEvent(webhookPayloadRepository) => unit)
      | `privatized(webhookEvent(webhookPayloadRepository) => unit)
      | `publicized(webhookEvent(webhookPayloadRepository) => unit)
      | `unarchived(webhookEvent(webhookPayloadRepository) => unit)
    ]
  ) =>
  unit;
let on_repository_import:
  (t, [ | `all(webhookEvent(webhookPayloadRepositoryImport) => unit)]) =>
  unit;
let on_repository_vulnerability_alert:
  (
    t,
    [
      | `all(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
      | `create(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
      | `dismiss(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
      | `resolve(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
    ]
  ) =>
  unit;
let on_security_advisory:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadSecurityAdvisory) => unit)
      | `performed(webhookEvent(webhookPayloadSecurityAdvisory) => unit)
      | `published(webhookEvent(webhookPayloadSecurityAdvisory) => unit)
      | `updated(webhookEvent(webhookPayloadSecurityAdvisory) => unit)
    ]
  ) =>
  unit;
let on_status:
  (t, [ | `all(webhookEvent(webhookPayloadStatus) => unit)]) => unit;
let on_team:
  (
    t,
    [
      | `added_to_repository(webhookEvent(webhookPayloadTeam) => unit)
      | `all(webhookEvent(webhookPayloadTeam) => unit)
      | `created(webhookEvent(webhookPayloadTeam) => unit)
      | `deleted(webhookEvent(webhookPayloadTeam) => unit)
      | `edited(webhookEvent(webhookPayloadTeam) => unit)
      | `removed_from_repository(webhookEvent(webhookPayloadTeam) => unit)
    ]
  ) =>
  unit;
let on_team_add:
  (t, [ | `all(webhookEvent(webhookPayloadTeamAdd) => unit)]) => unit;
let on_watch:
  (
    t,
    [
      | `all(webhookEvent(webhookPayloadWatch) => unit)
      | `started(webhookEvent(webhookPayloadWatch) => unit)
    ]
  ) =>
  unit;
let sign: (t, 'a) => string;
let verify: (t, 'a, string) => bool;
let verifyAndReceive:
  (
    t,
    {
      .
      id: string,
      name: string,
      payload: 'a,
      signature: string,
    }
  ) =>
  unit;
let receive:
  (
    t,
    {
      .
      id: string,
      name: string,
      payload: 'a,
    }
  ) =>
  unit;
let removeListener: (t, array(string), webhookEvent('a) => unit) => unit;
