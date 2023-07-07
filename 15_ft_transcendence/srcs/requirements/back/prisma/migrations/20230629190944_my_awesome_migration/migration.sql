-- CreateTable
CREATE TABLE "invitation" (
    "id" SERIAL NOT NULL,
    "type" TEXT NOT NULL,
    "whereID" INTEGER NOT NULL,
    "whoInviteUserName" TEXT NOT NULL,
    "invitedID" INTEGER NOT NULL DEFAULT -1,

    CONSTRAINT "invitation_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "invitation" ADD CONSTRAINT "invitation_invitedID_fkey" FOREIGN KEY ("invitedID") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
